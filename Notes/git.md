# Git

🎮 Interactive Tutorial : [Learn Git Branching](https://learngitbranching.js.org/?locale=en_EN)

⌨️ Command Line Game: [Githug](https://github.com/Gazler/githug)

🕸️ Game: [Oh My Git!](https://ohmygit.org/)

## Git Project Workflow

A Git project has three parts:

-  A `Working Directory`: where files are created, edited, deleted, and organized
-  A `Staging Area`: where changes that are made to the working directory are listed
-  A `Repository`: where Git permanently stores changes as different versions of the project

The Git workflow consists of editing files in the working directory, adding files to the staging area, and saving changes to a Git repository.

![Git Workflow](https://pbs.twimg.com/media/Fw3gzg8XgAQ1akF.jpg)

## Init

Initialize a git repository with a `.git` folder:

```shell
git init
```

## Status

![Git file status lifecycle](https://pbs.twimg.com/media/Fa1bAMzWQAAwXsw?format=jpg&name=4096x4096)

## Mv

### Rename

Rename a file:

```shell
git mv file new_file
```

### Move

Move a file:

```shell
git mv file directory
```

Move multiple files:

```shell
git mv file1 file2 directory
```

```shell
git mv *.html directory
```

## Position

### HEAD

The `HEAD` is a reference to the last commit in the currently checked-out branch. It's essentially a pointer to the most recent commit, and it's used by Git to determine the current state of the repository.

### HEAD^

The `HEAD^` is a reference to the commit before the current `HEAD`. It's essentially a pointer to the parent of the current commit.

Example:

```shell
git show HEAD^
```

### HEAD~n

The `HEAD~n` is a reference to the nth commit before the current `HEAD`. It's essentially a pointer to the nth parent of the current commit.

Example:

```shell
git show HEAD~3
```

## Commit

Commit send the files from the staging area to the repository:

```shell
git commit -m "Message"
```

### Amend

Amend allow to modify a commit:

```shell
git commit --amend -m "Message"
```

### Future Date

Committing with a future date in Git is generally not recommended as it can lead to confusion and inconsistencies in your repository's history. However, if you still want to do it, you can use the `GIT_COMMITTER_DATE` and `GIT_AUTHOR_DATE` environment variables to set the date for a commit. Here's an example:

```shell
GIT_COMMITTER_DATE="2022-12-31 12:00:00" GIT_AUTHOR_DATE="2022-12-31 12:00:00" git commit -m "Future commit"
```

In this example, the commit will be dated "2022-12-31 12:00:00". Please replace the date and time with your desired future date and time. The date and time must be in the format "YYYY-MM-DD HH:MM:SS".

Remember, this can cause issues with your repository and is generally not a good practice. Use it with caution.

## Tag

```mermaid
%%{init: { 'logLevel': 'debug', 'theme': 'default' , 'themeVariables': {
              'tagLabelColor': '#ff00ff',
              'tagLabelBackground': '#ffffff',
              'tagLabelBorder': '#ff00ff'
       } } }%%
gitGraph
  commit
  commit type: HIGHLIGHT tag: "Test"
  commit
```

Tags make it easier to navigate through the repository, allowing you to quickly jump to a specific point in your project's history. Unlike `branches`, which have history and contain changes, a tag is a static point in history.

The most common use for `tags` is to signify a specific release, or a point in history that should be preserved. For example, when you release a new version of your software, you might want to tag the commit that constitutes the `new release`. This way, even if you continue developing and adding new commits to the repository, you can always jump back to the point when you made the `release`.

### Create

Create a tag for a commit:

```shell
git tag -a tag -m "Message"
```

<details>
<summary>Example</summary>

To create a tag for a commit in Git, you can use the `git tag` command followed by the `-a` option (which creates an annotated tag), the tag name, and the `-m` option to provide a message for the tag. Here's an example:

```shell
git tag -a v1.0 -m "First version release"
```

In this example, `v1.0` is the tag name and `"First version release"` is the message associated with the tag. This command will create a tag for the latest commit. If you want to tag a specific commit, you can specify the commit hash at the end of the command:

```shell
git tag -a v1.0 -m "First version release" commit_hash
```

Replace `commit_hash` with the hash of the commit you want to tag.

</details>

### Push

To push a tag to a remote repository in Git, you can use the `git push` command followed by the name of the remote (usually `origin`) and the name of the tag. Here's an example:

```shell
git push origin tagname
```

Replace `tagname` with the name of your tag.

If you want to push all tags to the remote repository, you can use the `--tags` option:

```shell
git push origin --tags
```

### Delete

Delete a tag:

```shell
git tag -d tag
```

Delete a tag from remote repository:

```shell
git push origin --delete tag
```

### List

List all tags:

```shell
git tag
```

## Fetch

The `git fetch` command is used to download commits, files, and refs from a remote repository into your local repo. Fetching is what you do when you want to see what everybody else has been working on. It's similar to `git pull`, but doesn't merge changes.

Here are some common uses of `git fetch`:

- `git fetch`: Fetches all branches from the remote repository.
- `git fetch <remote>`: Fetches all branches from the specified remote repository.
- `git fetch <remote> <branch>`: Fetches a specific branch from the remote repository.
- `git fetch --all`: Fetches all remotes.
- `git fetch --prune`: Fetches all remotes and also removes any remote tracking branches which no longer exist on the remote.

## Pull

The `git pull` command is used to fetch and download content from a remote repository and immediately update the local repository to match that content. It is essentially a combination of `git fetch` followed by `git merge`.

Here are some common uses of `git pull`:

- `git pull`: Fetches the branch's latest changes from the remote repository and merges them into the local checked-out branch.
- `git pull <repository> <branch>`: Fetches the specified branch from the repository and merges it into the current branch.
- `git pull --rebase`: Instead of merging, it rebases the current branch onto the fetched branch.
- `git pull --all`: Fetches all remotes and their branches.

## Rebase

The `git rebase` command is used to move or combine a sequence of commits to a new base commit. It's a way to integrate changes from one branch into another. 

Here are some common uses of `git rebase`:

- `git rebase <base>`: Rebase the current branch onto `<base>`. `<base>` can be a commit ID, branch name, a tag, or a relative reference to HEAD.
- `git rebase -i <base>` or `git rebase --interactive <base>`: This starts an interactive rebase session where you can alter individual commits in the current branch. This is often used to squash or remove specific commits.
- `git rebase --continue`: This continues the rebase process after resolving a merge conflict.
- `git rebase --abort`: This stops the rebase process and returns the branch to the state it was in before `git rebase` was called.

## Reset

Reset allow to remove files from the staging area:

```shell
git reset HEAD file
```
or
```shell
git reset file
```

Reset allow to remove all files from the staging area:

```shell
git reset HEAD .
```

Reset allow to change the HEAD of the repository:

```shell
git reset commit
```

### Soft

A soft reset in Git is a way to undo commits while keeping the changes in the staging area (also known as the index). When you perform a soft reset, the HEAD pointer is moved to a previous commit, but the changes from the undone commits are kept in the staging area, ready to be committed again.

You can perform a soft reset with the `git reset --soft` command followed by the reference to the commit you want to reset to. For example, to undo the last commit while keeping the changes staged, you would use:

```shell
git reset --soft HEAD~1
```

In this command, `HEAD~1` refers to the commit before the current one. The changes from the undone commit will be kept in the staging area.

## Checkout

```mermaid
gitGraph
  commit
  commit
  branch developement
  checkout developement
  commit
  checkout main
  commit
```

The `git checkout` command is used to switch between different versions of a target entity. The target can be a file, a commit, or a branch.

Here are some common uses of `git checkout`:

- `git checkout <branch>`: Switches to the specified branch and updates the working directory.
- `git checkout -b <new-branch>`: Creates a new branch and switches to it.
- `git checkout <commit>`: Switches the HEAD to point to the specified commit.
- `git checkout -- <file>`: Discards changes in the working directory for the specified file.
- `git checkout HEAD -- <file>`: Restores the specified file to the state of the last commit.

Checkout allow to change the branch:

```shell
git checkout branch
```

Restore all files in working area to last commit in HEAD :

```shell
git checkout HEAD -- .
```

Restore a file to last commit :

```shell
git checkout file
```

### Tag

Checkout to a flag:

```shell
git checkout flag
```

Checkout to a flag when there is a conflict (same name of branch and flag):

```shell
git checkout refs/tags/<tag_name>
```

### Branch

Create a new branch and switch to it:

```shell
git checkout -b branch
```

Create a new branch and switch to it from a specific commit:

```shell
git checkout -b branch commit
```

Create a new branch and switch to it from a specific position:

```shell
git checkout -b branch HEAD~1
```

## Ignore

Example of file `.gitignore`

```gitignore
# Program
program
program_bonus

# Files generated to ignore
*.a
*.o
*.so
*.out
*.txt

# Prevent send of git ignore into project
.gitignore

# miniLibX
/mlx/

# VSCode
.vscode/

# Test
/Test/
```

### Exclude

To ignore all except some files:

```gitignore
# Ignore all files
*
# Except
!file_to_keep
```

## Branch

The `git branch` command is used to manage branches in your repository. A branch represents an independent line of development in your project, and serves as a pointer to a specific commit.

Here are some common uses of `git branch`:

- `git branch`: Lists all local branches in the current repository.
- `git branch -a`: Lists all local and remote branches.
- `git branch <branch>`: Creates a new branch named `<branch>`.
- `git branch -d <branch>`: Deletes the specified branch. This is a safe operation because it prevents deletion of a branch that has unmerged changes.
- `git branch -D <branch>`: Force deletes the specified branch, even if it has unmerged changes.
- `git branch -m <oldname> <newname>`: Renames a branch from `<oldname>` to `<newname>`.

### Quick Branch

Create a new branch and switch to it:

```shell
git checkout -b branch
```

## Remote

The `git remote` command is used to manage the set of repositories ("remotes") whose branches you track. Here are some common uses of `git remote`:

- `git remote -v`: Lists all remote repositories and their URLs.
- `git remote add <name> <url>`: Adds a new remote repository with the specified name and URL.
- `git remote remove <name>`: Removes the remote repository with the specified name.
- `git remote rename <old-name> <new-name>`: Renames a remote repository from old-name to new-name.
- `git remote set-url <name> <new-url>`: Changes the URL of the remote repository.


## Stash

Stash is a temporary storage for changes to commit later. This is useful when you want to pull changes from remote repository while you have local changes that are not ready or worthy to commit.

Allow to save current work in a stash:

```shell
git stash
```

The stash can be retrieved with:

```shell
git stash pop
```

## Tree of Repository: ls-tree

List content of a branch:

```shell
git ls-tree main --name-only --full-tree
```

List content of a branch with subdirectory:

```shell
git ls-tree main --name-only --full-tree */*
```

## Diff

Show difference between two commits:

```shell
git diff commit1 commit2
```

## Blame

The `git blame` command is used to determine who made a particular change, or what changes were made in a particular commit. It shows what revision and author last modified each line of a file.

Here are some common uses of `git blame`:

- `git blame <file>`: Shows the revision, author and time for each line of the specified file.
- `git blame -L <start>,<end> <file>`: Shows the revision, author and time for each line of the specified range in the file.
- `git blame <revision> -- <file>`: Shows the revision, author and time for each line of the file at the specified revision.

## Log

Allow to see the history of commits:

```shell
git log
```

To see the history of commits with the different branches:

```shell
git log --all --decorate --oneline --graph
```

### Show

Show the content of a commit:

```shell
git show commit
```

## Config

### User

#### User Name and Email Configuration

Set the user name:

```shell
git config --global user.name "Name"
```

Set the user email:

```shell
git config --global user.email "
```

See the user name:

```shell
git config user.name
```

See the user email:

```shell
git config user.email
```

### Alias

Allow to create alias for git command:

Example:

```shell
git config --global alias.lg "log --all --decorate --oneline --graph"
```

```shell
git lg
```
