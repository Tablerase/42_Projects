# Git

🎮 Interactive Tutorial : [Learn Git Branching](https://learngitbranching.js.org/?locale=en_EN)

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

## Reset

Reset allow to remove files from the staging area:

```shell
git reset HEAD file

```

Reset allow to change the HEAD of the repository:

```shell
git reset commit
```

## Checkout

Restore all files to last commit :

```shell
git checkout HEAD -- .
```

## Ignore

Example of file `.gitignore`

```gitignore
# Program
program_name

# Files generated to ignore
*.a
*.o
*.so
*.out

# Prevent send of git ignore into project
.gitignore

# miniLibX
/mlx/
```

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

### Alias

Allow to create alias for git command:

Example:

```shell
git config --global alias.lg "log --all --decorate --oneline --graph"
```

```shell
git lg
```
