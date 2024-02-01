# MiniShell

## Description

| Item | Description |
| --- | --- |
| Program name | **minishell** |
| Turn in files | `Makefile`, `*.h`, `*.c` |
| Makefile | `NAME`, `all`, `clean`, `fclean`, `re` |
| Arguments |  |
| External functs. | readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs|
| Libft authorized | Yes |
| Description | Write a shell |

### Infos

`readline()` can cause some leaks, it's a known issue, no need to worry about it.

### Mandatory

Needed to be able to do:

- Show a prompt when waiting for a new command
- Working **History**
- Working with absolute and relative path to execute a command
- One global variable: to handle the received signal
- Handle single quotes `'` (prevent interpretation of meta characters)
- Handle double quotes `"` (prevent interpretation of meta characters except for `$`)
- Handle **redirections**:
  - `<` redirect input
  - `>` redirect output
  - `<<` takes a `delimiter` and redirect input in a `heredoc` fashion until the delimiter is found. (Doesnt need an history)
  - `>>` redirect output with `append mode`
- Handle pipes `|`
- Handle **environment variables** `$`(followed by a sequence of characters) : `$PATH`, `$HOME`, `$USER`, `$PWD` etc... (See `man environ` for more informations)
- Handle exit status `$?`
- Handle signals:
  - `ctrl-C`: display a new prompt on a newline
  - `ctrl-D`: exit the shell
  - `ctrl-\`: do nothing
- Handle builtins:
  - `echo` with option `-n`
  - `cd` with only a relative or absolute path
  - `pwd` without any options
  - `export` without any options
  - `unset` without any options
  - `env` without any options and any arguments
  - `exit` without any options

### Bonus

- Handle `&&` and `||` with parenthesis `()` for priority
- Wildcards `*` should work for the current directory

## Notions

### Interacting Mode

In a shell environment, an interactive shell is one that allows a user to input commands and receive output. This shell reads startup files that occur during activation and displays a prompt. It also enables job control by default. An example of starting an interactive shell is by typing bash after logging into the system. The prompt variable for an interactive shell is set to `$PS1`. Interactive scripts require user input and cannot run in the background.

#### PS1 : Prompt String 1

<div>
  <span style="color: green;">[user@host</span>
  <span style="color: blue;"> ~]</span>
  <span style="color: red;">$</span>
  </br>
</div>

Different variable to customize the prompt: [🔗 bash syntax prompt](https://ss64.com/bash/syntax-prompt.html)

WebSite to customize PS1: [🔗 prompt preview](https://www.kirsle.net/wizards/ps1.html)

#### Non-interactive Mode

On the other hand, a non-interactive shell does not interact with the user. It can be run through a script or an automated process. In this case, .bashrc and .profile files do not get executed. Non-interactive scripts can run in the background smoothly. This shell is typically a non-login shell because the calling user has already logged in. A shell running a script is always considered a non-interactive shell

### Builtins

