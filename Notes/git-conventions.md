# Git Naming Conventions

## Resources

- [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
- [Example of commits](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)
- [Medium - Git Branching Naming Conventions](https://medium.com/@abhay.pixolo/naming-conventions-for-git-branches-a-cheatsheet-8549feca2534)

## Commits

```bash
# Commit Template message
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

Example:

```bash
# Commit with type and description
feat: add email notifications on new direct messages
```

```bash
# Commit with scope
feat(shopping cart): add the amazing button
```

```bash
# Commit with multiple lines
fix: prevent racing of requests

Introduce a request id and a reference to latest request. Dismiss
incoming responses other than from latest request.

Remove timeouts which were used to mitigate the racing issue but are
obsolete now.

Reviewed-by: Z
Refs: #123
```

| Type     | Meaning                                                                                                 |
| -------- | ------------------------------------------------------------------------------------------------------- |
| feat     | A new feature.                                                                                          |
| fix      | A bug fix.                                                                                              |
| docs     | Documentation only changes.                                                                             |
| style    | Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc). |
| refactor | A code change that neither fixes a bug nor adds a feature.                                              |
| perf     | A code change that improves performance.                                                                |
| ops      | Changes to the deployment process or scripts.                                                           |
| test     | Adding missing tests.                                                                                   |
| build    | Changes to the build process or auxiliary tools and libraries such as documentation generation.         |
| revert   | Reverts a previous commit.                                                                              |

### Description

- The description is a short summary of the changes.
  - It should not exceed 50 characters.
- It should be in the imperative mood.
  - `add`, `change`, `fix`, `remove`, `update`, etc.
  - `add` instead of `added`, `adding`, `adds`.
- It should not end with a period.

### Breaking Changes

```bash
# Commit with breaking change
feat!: remove ticket list endpoint

refers to JIRA-1337

BREAKING CHANGES: ticket enpoints no longer supports list all entites.
```

- `!` is used to indicate a breaking change.
- `BREAKING CHANGES` is a keyword that introduces a breaking change.
  - It is followed by a colon and a space.
  - It is followed by a description of the breaking change.

## Branches

```bash
# Branch Template
<type>/[T-number-]<name>
```

Example:

```bash
# Feature from Ticket(Jira or Trello) or Issue(GitHub)
feature/feature-name
feature/T-number-feature-name
```

```bash
# Hotfix
hotfix/T-number-hotfix-name
```

```bash
# Release
release/v1.0.0
```

| Type    | Meaning                                                                    |
| ------- | -------------------------------------------------------------------------- |
| wip     | Work in progress.                                                          |
| draft   | A draft branch.                                                            |
| fix     | A branch that fixes a bug.                                                 |
| feature | A branch that adds a new feature.                                          |
| hotfix  | A branch that fixes a bug in production.                                   |
| test    | A branch that tests a new feature or bugfix.                               |
| release | A branch that prepares for a new production release.                       |
| stable  | A branch that marks a stable release.                                      |
| develop | A branch where the latest developments, features and updates are combined. |
| main    | The main branch.                                                           |
