# MiniShell

## Table of Contents

* [Description](#description)
* [Notions](#notions)
  * [Interacting Mode](#interacting-mode)
    * [Prompt Statement Variables](#prompt-statement-variables)
      * [PS1 : Prompt Statement 1](#ps1--prompt-statement-1)
    * [Non-interactive Mode](#non-interactive-mode)
  * [Builtins](#builtins)
  * [Signals](#signals)
  * [Operator Precedence](#operator-precedence)
    * [Precedence Level](#precedence-level)
  * [Wildcards](#wildcards)
* [Fonctions](#fonctions)

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

Dont handle unclosed `'` or `"` and the special characters (that are not required by subject) like: `\` and `;`

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

In a shell environment, an interactive shell is one that allows a user to input commands and receive output. This shell reads startup files that occur during activation and displays a prompt. It also enables job control by default. An example of starting an interactive shell is by typing bash after logging into the system. The `prompt variable` for an interactive shell is set to `$PS1`. Interactive scripts require user input and cannot run in the background.

#### Prompt Statement Variables

- `PS1` – Default interactive prompt (this is the variable most often customized)
- `PS2` – Continuation interactive prompt (when a long command is broken up with `\` at the end of the line) default=">"
- `PS3` – Prompt used by “select” loop inside a shell script
- `PS4` – Prompt used when a shell script is executed in debug mode (“set -x” will turn this on) default ="++"
- `PROMPT_COMMAND` - If this variable is set and has a non-null value, then it will be executed just before the PS1 variable.

##### PS1 : Prompt Statement 1

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

In programming, the term "built-in" typically refers to functions or features that are included within a programming language, application, or tool, and can be accessed by end users without the need to import any external libraries or modules.

### Signals

In programming, a signal refers to a software-generated interrupt sent to a process by the Operating System (OS) due to an event or a change in state. These events could be triggered by user input, hardware interactions, or the system itself. Signals serve as an indicator that some state or data has changed, often accompanied by additional information about the change that has occurred.

There are two main types of signal programming: synchronous and asynchronous. Synchronous signal programming refers to events that occur sequentially, like sequences of samples or video frames, while asynchronous signal programming deals with events that occur independently, like messages in a message-passing architecture.

In the context of Unix-like operating systems, signals are a form of inter-process communication. They allow processes to communicate with each other and the kernel. For example, a process can send a SIGTERM signal to another process to ask it to terminate gracefully

### Operator Precedence

In shell scripting, `&&` and `||` are logical operators used to combine conditional statements. The && operator represents logical AND, meaning both conditions must be true for the entire condition to be true. The || operator represents logical OR, meaning if either one of the conditions is true, the entire condition is true.

Both && and || have the same precedence level, but unlike in many other programming languages, they are **left-associative**. This means that *in the absence of parentheses, the operations are performed from left to right*.

However, parentheses can be used to control the order of operations.

By default, the shell evaluates commands in parentheses first. This can be useful when you want to override the default left-associativity of `&&` and `||`. Here is an example:

```shell
$ command1 && (command2 || command3)
```

In this case, `command1` is executed first. If `command1` succeeds (returns a zero exit status), then `command2` is executed. If `command2` fails (returns a non-zero exit status), then `command3` is executed.

```shell
$ (command1 && command2) || command3
```

The shell first evaluates `command1` && `command2`. If both `command1` and `command2` succeed, then the entire expression is true, and `command3` is not executed. If either `command1` or `command2` fails, then the entire expression is false, and `command3` is executed

#### Precedence Level

In programming, the term "precedence level" refers to the order in which operations are executed in an expression that includes multiple operators. This is determined by the operator's precedence, which is essentially a ranking of operators based on the order in which they should be evaluated.

For instance, consider the expression `10 + 20 * 30`. Here, the `*` operator has higher precedence than the `+` operator, meaning that the multiplication operation is performed first. So, the expression is evaluated as `10 + (20 * 30)`, resulting in `610`.

Precedence levels help to resolve ambiguity in expressions where an operator could potentially be associated with more than one operand. In such cases, the operator with the higher precedence level is chosen.

### Wildcards

In computing, a wildcard refers to a **character or string** that can be **used as a substitute for any other character or characters in a string**. Wildcards are commonly used in file management and programming for tasks such as listing or opening multiple files or searching for files with a similar extension.

In Unix-like operating systems, wildcards are supported by the shell (command line interpreter), which is responsible for expanding wildcards before commands are executed. The most common wildcards are the asterisk (`*`) and question mark (`?`) characters, which represent zero or more characters and a single character, respectively. For example, the wildcard `*.txt` represents all files with the `.txt` extension, while the wildcard `?.txt` represents all files with a single character followed by the `.txt` extension.

Examples of Wildcards:

- `*` - Matches zero or more characters
- `?` - Matches a single character
- `[characters]` - Matches any character in the set
- `[!characters]` - Matches any character not in the set
- `[[:class:]]` - Matches any character in the specified class
- `[![:class:]]` - Matches any character not in the specified class

Examples of usage in the shell:

```shell
$ ls report*.txt
```

```shell
report.txt report1.txt report2.txt report4.txt
```

Wildcards can also be used to represent a range of characters. For example, the wildcard `[a-z]` represents all lowercase letters, while the wildcard `[0-9]` represents all numbers. The wildcard `[!a-z]` represents all characters except lowercase letters.

## Fonctions

- `readline`: Reads a line from the terminal and returns it. Used in command line interfaces.

- `rl_clear_history`: Clears the readline history.

- `rl_on_new_line`: Informs readline that the cursor is on a new line.

- `rl_replace_line`: Replaces the current line in readline with the given text.

- `rl_redisplay`: Redraws the current line.

- `add_history`: Adds a line to the readline history.

- `printf`: Prints formatted output to stdout.

- `malloc`: Allocates a block of memory.

- `free`: Deallocates a block of memory.

- `write`: Writes data to a file or a file descriptor.

- `access`: Checks the accessibility of a file.

- `open`: Opens a file or device.

- `read`: Reads data from a file or a file descriptor.

- `close`: Closes a file or a file descriptor.

- `fork`: Creates a new process.

- `wait`: Waits for a process to change state.

- `waitpid`: Waits for a specific process to change state.

- `wait3`: Waits for a child process to stop or terminate.

- `wait4`: Waits for a child process to stop or terminate, with resource usage information.

- `signal`: Sets a function to handle a signal.

- `sigaction`: Examines and changes a signal action.

- `sigemptyset`: Initializes a signal set to empty.

- `sigaddset`: Adds a signal to a signal set.

- `kill`: Sends a signal to a process or a group of processes.

- `exit`: Terminates the process.

- `getcwd`: Gets the current working directory.

- `chdir`: Changes the current working directory.

- `stat`: Gets file status.

- `lstat`: Like `stat`, but if the file is a symbolic link, then it returns information about the link itself, not the file it refers to.

- `fstat`: Like `stat`, but takes a file descriptor instead of a file name.

- `unlink`: Deletes a name from the filesystem.

- `execve`: Executes a program.

- `dup`: Duplicates a file descriptor.

- `dup2`: Duplicates a file descriptor to a specified file descriptor.

- `pipe`: Creates a pipe.

- `opendir`: Opens a directory.

- `readdir`: Reads a directory.

- `closedir`: Closes a directory.

- `strerror`: Returns a string describing an error number.

- `perror`: Prints a descriptive error message to stderr.

- `isatty`: Tests whether a file descriptor refers to a terminal.

- `ttyname`: Returns the name of the terminal.

- `ttyslot`: Returns the terminal slot number.

- `ioctl`: Controls device.

- `getenv`: Gets an environment variable.

- `tcsetattr`: Sets the parameters associated with the terminal.

- `tcgetattr`: Gets the parameters associated with the terminal.

- `tgetent`: Loads the termcap entry for terminal.

- `tgetflag`: Returns the boolean value of capability.

- `tgetnum`: Returns the numeric value of capability.

- `tgetstr`: Returns the string value of capability.

- `tgoto`: Moves the cursor to specified position.

- `tputs`: Applies padding information to a string and outputs it.
