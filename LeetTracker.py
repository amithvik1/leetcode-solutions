import requests
import json
import os

# ==========================================================
# CONFIGURATION
# ==========================================================

USERS = [
    {
        "name": "Amith",
        "github": "amithvik1",
        "repo": "leetcode-solutions"
    },
    {
        "name": "Aniruddha",
        "github": "aniruddhaks2006-png",
        "repo": "leetcode-solutions"
    },
    {
        "name": "",      # Person 3
        "github": "",
        "repo": ""
    }
]

GITHUB_TOKEN = ""

CACHE_FILE = "leetcode_metadata_cache.json"

# ==========================================================
# LEETCODE METADATA
# ==========================================================

def get_leetcode_metadata():

    if os.path.exists(CACHE_FILE):
        try:
            with open(CACHE_FILE, "r", encoding="utf-8") as f:
                print("📦 Using cached LeetCode metadata")
                return json.load(f)
        except:
            pass

    print("🌐 Downloading LeetCode metadata...")

    url = "https://leetcode.com/api/problems/all/"

    response = requests.get(
        url,
        headers={"User-Agent": "Mozilla/5.0"},
        timeout=30
    )

    if response.status_code != 200:
        print("⚠️ Failed to fetch LeetCode metadata.")
        return {}

    difficulty_map = {
        1: "Easy",
        2: "Medium",
        3: "Hard"
    }

    metadata = {}

    for item in response.json()["stat_status_pairs"]:

        slug = item["stat"]["question__title_slug"]

        metadata[slug] = {
            "number": str(
                item["stat"]["frontend_question_id"]
            ).zfill(4),
            "title": item["stat"]["question__title"],
            "difficulty": difficulty_map[
                item["difficulty"]["level"]
            ]
        }

    with open(CACHE_FILE, "w", encoding="utf-8") as f:
        json.dump(metadata, f)

    return metadata


# ==========================================================
# GITHUB HELPERS
# ==========================================================

def detect_default_branch(username, repo):

    headers = {
        "User-Agent": "Leetcode-Team-Analyzer"
    }

    if GITHUB_TOKEN:
        headers["Authorization"] = f"token {GITHUB_TOKEN}"

    url = f"https://api.github.com/repos/{username}/{repo}"

    r = requests.get(url, headers=headers)

    if r.status_code != 200:
        return "main"

    return r.json().get("default_branch", "main")


def get_solved_problems(username, repo):

    if not username or not repo:
        return set()

    branch = detect_default_branch(username, repo)

    url = (
        f"https://api.github.com/repos/"
        f"{username}/{repo}/git/trees/"
        f"{branch}?recursive=1"
    )

    headers = {
        "User-Agent": "Leetcode-Team-Analyzer"
    }

    if GITHUB_TOKEN:
        headers["Authorization"] = f"token {GITHUB_TOKEN}"

    response = requests.get(url, headers=headers)

    if response.status_code != 200:
        print(
            f"⚠️ Failed to load "
            f"{username}/{repo}"
        )
        return set()

    solved = set()

    for item in response.json().get("tree", []):

        parts = item["path"].split("/")

        if (
            len(parts) >= 2
            and parts[0].lower() == "solutions"
            and item["type"] == "tree"
        ):
            solved.add(parts[1])

    return solved


# ==========================================================
# HELPERS
# ==========================================================

def extract_slug(folder_name):

    parts = folder_name.split("-", 1)

    if len(parts) == 2:
        return parts[1]

    return folder_name


def get_problem_info(folder_name, metadata):

    slug = extract_slug(folder_name)

    return metadata.get(
        slug,
        {
            "number": "????",
            "title": slug.replace("-", " ").title(),
            "difficulty": "Unknown"
        }
    )


# ==========================================================
# DISPLAY HELPERS
# ==========================================================

def print_by_difficulty(problem_set, title, metadata):

    grouped = {
        "Easy": [],
        "Medium": [],
        "Hard": [],
        "Unknown": []
    }

    for p in problem_set:

        info = get_problem_info(p, metadata)

        grouped[info["difficulty"]].append(p)

    print("\n" + "=" * 100)
    print(title)
    print("=" * 100)

    if not problem_set:
        print("🎉 Nothing here!")
        return

    for diff in ["Easy", "Medium", "Hard", "Unknown"]:

        entries = grouped[diff]

        if not entries:
            continue

        entries.sort(
            key=lambda x:
            int(
                get_problem_info(
                    x,
                    metadata
                )["number"]
                .replace("?", "999999")
            )
        )

        print(f"\n📌 {diff} ({len(entries)})")
        print("-" * 50)

        for i, p in enumerate(entries, 1):

            info = get_problem_info(
                p,
                metadata
            )

            print(
                f"{i}. "
                f"[{info['number']}] "
                f"{info['title']}"
            )


# ==========================================================
# LEADERBOARD
# ==========================================================

def print_leaderboard(all_sets):

    print("\n" + "=" * 100)
    print("🏆 LEADERBOARD")
    print("=" * 100)

    leaderboard = sorted(
        all_sets.items(),
        key=lambda x: len(x[1]),
        reverse=True
    )

    medals = [
        "🥇",
        "🥈",
        "🥉"
    ]

    for rank, (name, solved) in enumerate(
        leaderboard,
        start=1
    ):

        medal = (
            medals[rank - 1]
            if rank <= 3
            else "  "
        )

        print(
            f"{medal} "
            f"{rank}. "
            f"{name:<15} "
            f"{len(solved)} solved"
        )


# ==========================================================
# UNIQUE PROBLEMS
# ==========================================================

def print_unique_problems(all_sets):

    print("\n" + "=" * 100)
    print("⭐ UNIQUE PROBLEMS")
    print("=" * 100)

    for name, my_set in all_sets.items():

        others = set()

        for other_name, other_set in all_sets.items():

            if other_name != name:
                others |= other_set

        unique = my_set - others

        print(
            f"{name:<15} "
            f"{len(unique)} unique problems"
        )


# ==========================================================
# CATCH-UP RECOMMENDATIONS
# ==========================================================

def print_catchup_recommendations(
    all_sets,
    metadata
):

    print("\n" + "=" * 100)
    print("🚀 CATCH-UP RECOMMENDATIONS")
    print("=" * 100)

    for name, my_set in all_sets.items():

        others = [
            s
            for n, s in all_sets.items()
            if n != name
        ]

        if not others:
            continue

        common = set.intersection(*others)

        recommended = common - my_set

        print_by_difficulty(
            recommended,
            f"Problems solved by EVERYONE else but missing for {name} ({len(recommended)})",
            metadata
        )


# ==========================================================
# PAIRWISE COMPARISONS
# ==========================================================

def run_pairwise_comparisons(
    all_sets,
    metadata
):

    names = list(all_sets.keys())

    for i in range(len(names)):

        for j in range(i + 1, len(names)):

            a = names[i]
            b = names[j]

            set_a = all_sets[a]
            set_b = all_sets[b]

            print("\n\n" + "#" * 100)
            print(f"⚔️ {a} VS {b}")
            print("#" * 100)

            print_by_difficulty(
                set_b - set_a,
                f"{b} solved but {a} is missing ({len(set_b-set_a)})",
                metadata
            )

            print_by_difficulty(
                set_a - set_b,
                f"{a} solved but {b} is missing ({len(set_a-set_b)})",
                metadata
            )


# ==========================================================
# MAIN
# ==========================================================

def main():

    metadata = get_leetcode_metadata()

    all_sets = {}

    print("\n🔄 Loading repositories...\n")

    for user in USERS:

        if not user["name"]:
            continue

        solved = get_solved_problems(
            user["github"],
            user["repo"]
        )

        all_sets[user["name"]] = solved

        print(
            f"✅ {user['name']}: "
            f"{len(solved)} solved"
        )

    print("\n" + "=" * 100)
    print("📊 SUMMARY")
    print("=" * 100)

    for name, solved in all_sets.items():

        print(
            f"{name:<15} "
            f"{len(solved)} solved"
        )

    print_leaderboard(all_sets)

    print_unique_problems(all_sets)

    print_catchup_recommendations(
        all_sets,
        metadata
    )

    run_pairwise_comparisons(
        all_sets,
        metadata
    )


if __name__ == "__main__":
    main()