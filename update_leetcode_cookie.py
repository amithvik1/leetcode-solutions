import os
import time
import base64
import requests
import browser_cookie3

from nacl import public, encoding
from dotenv import load_dotenv

load_dotenv()

GITHUB_PAT = os.getenv("GH_PAT")
OWNER = os.getenv("GITHUB_OWNER")
REPO = os.getenv("GITHUB_REPO")

if not all([GITHUB_PAT, OWNER, REPO]):
    raise Exception(
        "Missing GH_PAT, GITHUB_OWNER, or GITHUB_REPO in .env"
    )

headers = {
    "Authorization": f"token {GITHUB_PAT}",
    "Accept": "application/vnd.github+json"
}

print("Reading Chrome cookies...")

session_cookie = None

cookies = browser_cookie3.chrome(domain_name="leetcode.com")

for cookie in cookies:
    if cookie.name == "LEETCODE_SESSION":
        session_cookie = cookie.value
        break

if not session_cookie:
    raise Exception(
        "LEETCODE_SESSION cookie not found. "
        "Make sure you're logged into LeetCode in Chrome."
    )

print("Found LEETCODE_SESSION.")

print("Fetching repository public key...")

key_url = (
    f"https://api.github.com/repos/"
    f"{OWNER}/{REPO}/actions/secrets/public-key"
)

key_response = requests.get(
    key_url,
    headers=headers
)

key_response.raise_for_status()

key_data = key_response.json()

public_key = public.PublicKey(
    key_data["key"].encode(),
    encoding.Base64Encoder()
)

sealed_box = public.SealedBox(public_key)

encrypted_value = base64.b64encode(
    sealed_box.encrypt(
        session_cookie.encode()
    )
).decode()

print("Updating LEETCODE_SESSION secret...")

secret_url = (
    f"https://api.github.com/repos/"
    f"{OWNER}/{REPO}/actions/secrets/"
    f"LEETCODE_SESSION"
)

response = requests.put(
    secret_url,
    headers=headers,
    json={
        "encrypted_value": encrypted_value,
        "key_id": key_data["key_id"]
    }
)

if response.status_code not in [201, 204]:
    raise Exception(
        f"Failed to update secret:\n{response.text}"
    )

print("LEETCODE_SESSION updated.")

print("Triggering sync.yml...")

workflow_url = (
    f"https://api.github.com/repos/"
    f"{OWNER}/{REPO}/actions/workflows/"
    f"sync.yml/dispatches"
)

response = requests.post(
    workflow_url,
    headers=headers,
    json={
        "ref": "main"
    }
)

if response.status_code != 204:
    raise Exception(
        f"Failed to trigger sync.yml:\n"
        f"{response.status_code}\n"
        f"{response.text}"
    )

print("sync.yml triggered.")
print("Waiting 35 seconds for workflow completion...")

time.sleep(35)

runs_url = (
    f"https://api.github.com/repos/"
    f"{OWNER}/{REPO}/actions/workflows/"
    f"sync.yml/runs?per_page=1"
)

response = requests.get(
    runs_url,
    headers=headers
)

response.raise_for_status()

runs = response.json()["workflow_runs"]

if not runs:
    raise Exception(
        "No workflow runs found."
    )

run = runs[0]

print("\n========== RESULT ==========")
print("Status     :", run["status"])
print("Conclusion :", run["conclusion"])
print("Run URL    :", run["html_url"])
print("============================")

if run["conclusion"] == "success":
    print("\nSUCCESS: Cookie updated and sync completed.")
else:
    print(
        "\nWARNING: Cookie updated but sync workflow "
        "did not finish successfully."
    )
