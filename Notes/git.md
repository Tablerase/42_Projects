# Git

## Commit

```shell
git commit -m "Message"
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

## Tree of Repository: ls-tree

List content of a branch:

```shell
git ls-tree main --name-only --full-tree
```

List content of a branch with subdirectory:

```shell
git ls-tree main --name-only --full-tree */*
```
