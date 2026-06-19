# 🚀 The Ultimate Zero-Click LeetCode to GitHub Auto-Sync Guide

This guide sets up a background GitHub robot that automatically logs into your LeetCode account every single day, downloads every single problem you have ever solved (including your past history), and saves your code into a clean GitHub repository. 

**Zero manual copying, zero manual clicking, and 100% automated.**

---

### Step 1: Create Your GitHub Repository
1. Log into your **GitHub** account.
2. Click the **`+`** icon in the top-right corner and select **New repository**.
3. Name your repository something clean (e.g., `leetcode-solutions` or `leetcode-history`).
4. Set the visibility to **Public** (so your friend can see your progress).
5. Check the box that says **Add a README file**.
6. Click the green **Create repository** button.

---

### Step 2: Grab Your Hidden LeetCode Cookie
To allow the GitHub robot to securely fetch your code submissions, you need to provide it with your current account session token. 
1. Open a desktop browser, go to **LeetCode**, and log into your account.
2. Press **F12** (or right-click anywhere on the page and select **Inspect**) to open the Developer Tools panel.
3. Locate the storage tabs along the top menu bar of the Developer panel:
   * **On Chrome / Edge / Brave / Opera:** Click the **Application** tab, look at the left sidebar, expand the **Cookies** dropdown, and click `https://leetcode.com`.
   * **On Firefox:** Click the **Storage** tab, expand the **Cookies** dropdown on the left sidebar, and click `https://leetcode.com`.
4. Look through the table on the right side for a row where the **Name / Key** column says exactly: **`LEETCODE_SESSION`**.
5. Double-click the very long, messy text string in the **Value** column next to it and **copy it** to your clipboard.

---

### Step 3: Save Your Credentials in GitHub Secrets
1. Go back to your newly created GitHub repository page.
2. Click on the **Settings** tab located along the top menu bar.
3. On the left sidebar menu, scroll down to the **Security** section, click **Secrets and variables**, and select **Actions**.
4. Click the green **New repository secret** button in the top right.
5. In the **Name** input field, type exactly: `LEETCODE_SESSION`
6. In the **Secret** text area, paste the long text string you copied in Step 2.
7. Click **Add secret**.
8. Make another secret , name it `LEETCODE_USERNAME` and add your Leetcode Username to it. It is case sensitive , make sure to paste it properly.

---

### Step 4: Create the Automatic Workflow Script
1. Click back to the main **Code** tab of your GitHub repository.
2. Click the **Add file** dropdown button on the right side and choose **Create new file**.
3. In the file name field at the top, paste this exact directory path structure:
   ```text
   .github/workflows/sync.yml
   ```
4. Paste this exact configuration script into the main text editor window:

```yaml
name: Sync LeetCode Solves

on:
  workflow_dispatch:
  schedule:
    - cron: '0 0 * * *'

jobs:
  build:
    runs-on: ubuntu-latest
    permissions:
      contents: write
    steps:
      - name: Sync Solves
        uses: joshcai/leetcode-sync@master
        with:
          github-token: ${{ secrets.GITHUB_TOKEN }}
          leetcode-csrf-token: ''
          leetcode-session: ${{ secrets.LEETCODE_SESSION }}
          leetcode-username: ${{ secrets.LEETCODE_USERNAME }}
          filter-duplicate-secs: 86400
          destination-folder: 'solutions'

```

5. Click the green **Commit changes** button in the top-right corner, then click **Commit changes** a second time to save the file permanently.

---

### Step 5: Wake Up the Robot for the First Time
Your system is now built and will update on its own forever, but let's fire it up right now to pull all of your past solved questions instantly.

1. Click on the **Actions** tab at the top of your GitHub repository page.
2. On the left-hand menu under Actions, click on **Sync LeetCode Solves**.
3. Look across to the right side of the page, click the **Run workflow** dropdown button, and hit the green **Run workflow** action.

---

### 📊 What Happens Next?
The workflow will spin up. Give it about **2 to 3 minutes** to run through your entire history. Once it finishes, a **green checkmark** will appear showing a status of `Success`. 

Head back to your repository's main **Code** page—you will find a brand new folder called `solutions` packed full of every single problem you have ever solved, categorized with code files and readmes. From this point forward, you can close the tabs and forget about it; the workflow will wake up at midnight completely invisibly to pull your daily updates. 

Swap repository links with your friend so you can cross-reference your source code anytime!

---

---


# 🔄 Optional: Automatic Cookie Refresh

LeetCode occasionally expires your login session cookie. When that happens, the GitHub sync workflow will stop working until
 a fresh cookie is provided.

This repository includes a helper script that can automatically:

* Read your current LeetCode cookie from Chrome
* Update the GitHub Secret
* Trigger the sync workflow
* Verify that the sync completed successfully

Once configured, refreshing your cookie only takes a single command.

---

## 🔑 Step 1: Create a GitHub Personal Access Token

The script needs permission to update the `LEETCODE_SESSION` secret in your repository.

### Create a Classic Personal Access Token

1. Open GitHub.
2. Click your profile picture → **Settings**.
3. Scroll down and click **Developer settings**.
4. Click **Personal access tokens**.
5. Click **Tokens (classic)**.
6. Click **Generate new token (classic)**.

### Token Name

Use any name you like:

```text id="gt04ui"
LeetCode Cookie Updater
```

### Expiration

Choose any expiration period you prefer.

Examples:

```text id="g17coh"
30 days
90 days
1 year
```

### Select Scopes

Enable:

```text id="uxzkju"
repo
workflow
```

These permissions allow the script to:

* Update your `LEETCODE_SESSION` GitHub Secret
* Trigger the LeetCode sync workflow

### Generate the Token

Click:

```text id="az9kjw"
Generate token
```

Copy the token immediately.

GitHub will only display it once.

The token should look similar to:

```text id="v4fys4"
ghp_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
```

---

## ⚠️ Important Security Warning

Your GitHub Personal Access Token gives access to your repositories.

Treat it exactly like a password.

Never:

* Share it with anyone
* Post screenshots containing it
* Upload it to GitHub
* Commit it into source code
* Send it through Discord, Telegram, Reddit, or social media

If you accidentally expose the token:

1. Go to GitHub → Settings → Developer Settings → Personal Access Tokens
2. Delete the token immediately
3. Generate a new one

---

## 📁 Create a .env File

Create a file named:

```text id="3x2lqm"
.env
```

Paste:

```env id="13egx7"
GH_PAT=your_github_token
GITHUB_OWNER=your_github_username
GITHUB_REPO=your_repository_name
```

Example:

```env id="czk25o"
GH_PAT=ghp_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
GITHUB_OWNER=amithvik1
GITHUB_REPO=leetcode-solutions
```

---

## ⚠️ Never Upload Your .env File

Your `.env` file contains your GitHub access token.

Never commit it to GitHub.

Never share screenshots of it.

Never send it to anyone.

Create a `.gitignore` file containing:

```gitignore id="nxlsr3"
.env
.venv/
__pycache__/
```

This prevents your token from accidentally being uploaded.
