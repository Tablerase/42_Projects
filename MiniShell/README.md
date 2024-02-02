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

- [`readline`](#readline): Reads a line from the terminal and returns it. Used in command line interfaces.

- [`rl_clear_history`](#rl_clear_history): Clears the readline history.

- [`rl_on_new_line`](#rl_on_new_line): Informs readline that the cursor is on a new line.

- [`rl_replace_line`](#rl_replace_line): Replaces the current line in readline with the given text.

- [`rl_redisplay`](#rl_redisplay): Redraws the current line.

- [`add_history`](#add_history): Adds a line to the readline history.

- `printf`: Prints formatted output to stdout.

- `malloc`: Allocates a block of memory.

- `free`: Deallocates a block of memory.

- `write`: Writes data to a file or a file descriptor.

- [`access`](/Pipex/README.md#access): Checks the accessibility of a file.

- `open`: Opens a file or device.

- `read`: Reads data from a file or a file descriptor.

- `close`: Closes a file or a file descriptor.

- [`fork`](/Pipex/README.md#fork): Creates a new process.

- [`wait`](/Pipex/README.md#wait): Waits for a process to change state.

- [`waitpid`](/Pipex/README.md#waitpid): Waits for a specific process to change state.

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

### Readline

The `readline` function is part of the GNU Readline library, which provides a set of functions for use by applications that allow users to edit command lines as they are typed in. 

Here's a brief overview of how `readline` works:

1. When called, `readline` displays a prompt (if given) and waits for the user to input a line of text.

2. While waiting for input, `readline` provides a number of editing capabilities, including (but not limited to):
   - Moving the cursor left and right on the line
   - Deleting characters
   - Cutting and pasting text
   - Using history commands to recall previously entered lines

3. The line editing is done using key bindings and key sequences similar to those used in GNU Emacs or vi, depending on the Readline configuration.

4. Once the user presses the Enter key, `readline` returns the text of the line the user typed in. If the line is not empty, it is added to the history list for later recall.

5. If the user signals an end-of-file (usually by pressing Ctrl-D), `readline` returns a NULL pointer.

The `readline` function makes it easier to build interactive command-line applications by handling a lot of the line editing and history functionality that users expect from modern shells.

To use in C, you need to include the `readline/readline.h` header file and link against the Readline library using the `-lreadline` flag.

<details>
  <summary>Example</summary>

```c
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input;

    while(1) {
        input = readline(">> ");

        if (!input) {
            break;
        }

        add_history(input);
        printf("You entered: %s\n", input);

        free(input);
    }

    return 0;
}
```

```shell
gcc -o myprogram myprogram.c -lreadline
```

</details>

[🔗 Readline Documentation](https://tiswww.case.edu/php/chet/readline/readline.html)

[🔗 Readline Manual](https://www.gnu.org/software/bash/manual/html_node/Command-Line-Editing.html)

[🔗 Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html)

### rl_clear_history

The `rl_clear_history` function is part of the GNU Readline library. 

Here's a brief overview of how `rl_clear_history` works:

1. `rl_clear_history` is a function that clears the history list maintained by readline. 

2. The history list is a list of lines previously entered by the user. This list can be navigated using certain key bindings, allowing the user to easily recall and edit previous inputs.

3. When `rl_clear_history` is called, it removes all items from the history list, freeing the memory used by these items.

4. After `rl_clear_history` has been called, the history list is empty, and the user can no longer recall previous lines using the history navigation commands until new lines are added to the history.

<details>
  <summary>Example</summary>

Here's a simple example of how to use `rl_clear_history` in a C program:

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input;

    while(1) {
        input = readline(">> ");

        if (!input) {
            break;
        }

        add_history(input);
        printf("You entered: %s\n", input);

        if(strcmp(input, "clear_history") == 0) {
            rl_clear_history();
            printf("History cleared.\n");
        }

        free(input);
    }

    return 0;
}
```

In this example, the program clears the readline history when the user enters "clear_history".

</details>

### rl_on_new_line

The `rl_on_new_line` function is part of the GNU Readline library.

Here's a brief overview of how `rl_on_new_line` works:

1. `rl_on_new_line` is a function that informs the readline library that the cursor is on a new line.

2. This function is typically used after a newline character has been printed or the cursor has been moved to a new line in some other way.

3. It's used to maintain the internal state of the readline library, ensuring that it correctly tracks the position of the cursor.

4. It doesn't directly affect the user's input or the history list.

<details>

  <summary>Example</summary>

Here's an example of how you might use `rl_on_new_line` in a C program:

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input;

    while(1) {
        input = readline(">> ");

        if (!input) {
            break;
        }

        add_history(input);
        printf("You entered: %s\n", input);

        printf("\n");  // print a newline
        rl_on_new_line();  // inform readline that we're on a new line

        free(input);
    }

    return 0;
}
```

In this example, the program informs readline that it's on a new line after printing a newline character. This is not typically necessary in a simple readline loop like this, but it might be needed in more complex programs that manipulate the terminal in other ways.

For example, if your program prints a multi-line message to the terminal in the middle of a readline loop, you would want to call `rl_on_new_line` after printing the message to ensure that readline correctly tracks the cursor position.

</details>

### rl_replace_line

```c
/**
 * *Replaces the current line in readline with the given text.
 * @param text The text to replace the current line with.
 * @param clear_undo If non-zero, the replaced line will be saved in the undo list.
 * @return 0 on success, -1 on error.
 */
int rl_replace_line(const char *text, int clear_undo);
```

`rl_replace_line` is a function that is part of the GNU Readline library.

- It replaces the current line that readline is working with, with the text provided as an argument.

- This function is typically used when you want to programmatically change the text that the user is editing.

- It doesn't directly affect the history list, but the replaced line will be added to the history if the user presses Enter.

<details>

  <summary>Example</summary>

Here's an example of how you might use `rl_replace_line` in a C program:

```c
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input;

    while(1) {
        input = readline(">> ");

        if (!input) {
            break;
        }

        if(strcmp(input, "replace_line") == 0) {
            rl_replace_line("This line has been replaced.", 0);
            printf("The readline \"%s\" -> was replace with: \"%s\"\n", input, rl_copy_text(0, rl_end));
        } else {
            add_history(input);
            printf("You entered: %s\n", input);
        }

        free(input);
    }

    return 0;
}
```

In this example, the program replaces the current line with "This line has been replaced." when the user enters "replace_line".

The `rl_end` variable in the GNU Readline library refers to the index of the last character in the current line buffer (`rl_line_buffer`). The line buffer is where the input line being edited is stored. When the cursor is at the end of the line, `rl_point` and `rl_end` are equal. The `rl_end` variable is useful when you want to manipulate or retrieve the entire line from the line buffer.

</details>

### rl_redisplay

```c
void rl_redisplay(void);
```

`rl_redisplay` is a function that is part of the GNU Readline library.

- It redraws the current line that readline is working with.

- This function is typically used when you want to update the display after making changes to the line buffer programmatically.

### add_history

```c
/**
 * *Adds a line to the readline history.
 * @param string The line to add to the history.
 */
void add_history(const char *string);
```

`add_history` is a function that is part of the GNU Readline library.

- It adds a line to the history list maintained by readline.

- The history list is a list of lines previously entered by the user. This list can be navigated using certain key bindings, allowing the user to easily recall and edit previous inputs.

- When `add_history` is called, it adds the provided line to the history list, making it available for later recall.

