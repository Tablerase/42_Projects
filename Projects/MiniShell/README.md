# MiniShell

## Resources

- [📑 Article - How to write your own shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

- [📑 Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

- [📑 Bash Reference Manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)

## Table of Contents

* [Description](#description)
* [Notions](#notions)
  * [Lexer](#lexer)
  * [Interacting Mode](#interacting-mode)
    * [Prompt Statement Variables](#prompt-statement-variables)
      * [PS1 : Prompt Statement 1](#ps1--prompt-statement-1)
    * [Non-interactive Mode](#non-interactive-mode)
  * [Builtins](#builtins)
  * [Signals](#signals)
  * [Operator Precedence](#operator-precedence)
    * [Precedence Level](#precedence-level)
  * [Wildcards](#wildcards)
  * [Here string](#here-string)
  * [Restrict : `restrict` keyword](#restrict--restrict-keyword)
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

### Lexer

The lexer takes a string of characters as input and produces a sequence of tokens as output. Each token represents a single element of the input string, and the sequence of tokens represents the structure of the input string.

The output of the lexer is typically fed into a parser, which uses the tokens to build a more structured representation of the input string, such as an abstract syntax tree or a sequence of instructions.

**Lexing, or lexical analysis**, is the process of converting a sequence of characters into a sequence of tokens. In the context of a shell, the lexer is responsible for breaking up the command line input into recognizable tokens that can be processed by the shell's parser.

Here's a simplified overview of how lexing might be done in a shell:

1. **Reading Input**: The shell reads the command line input, which is a string of characters.

2. **Tokenizing**: The lexer goes through the input string character by character. It recognizes tokens based on certain patterns or rules. For example, a word might be defined as a sequence of alphanumeric characters, a redirection operator might be defined as the character '>', and so on.

3. **Handling Special Characters**: The lexer also needs to handle special characters like quotes. For example, everything inside double quotes is usually treated as a single token, even if it contains spaces.

4. **Whitespace and Separators**: Whitespace characters (spaces and tabs) are often used to separate tokens. Some special characters like semicolons can also act as separators.

5. **Producing Tokens**: The lexer produces a sequence of tokens that represent the original command line input. Each token includes information about its type (e.g., word, operator, etc.) and its value (the actual text of the token).

6. **Passing Tokens to the Parser**: The tokens are then passed to the parser, which is responsible for interpreting them and executing the corresponding commands.

This is a simplified overview and actual shell lexers can be quite complex. They need to handle a variety of special cases, such as variable substitution, command substitution, different types of quotes, escape sequences, and more.

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

### Here string

`<<<` is a shell feature that allows a string to be passed to a command's standard input. It is similar to a here document, but it is used to pass a string to a command instead of a block of text.

```shell
$ command <<< "string"
```

### Restrict : `restrict` keyword

The `restrict` keyword is a pointer qualifier used in C and C++ (in C++ it's not part of the language standard but can be used as a compiler extension). It was introduced in the C99 standard.

When a pointer is qualified with `restrict`, it tells the compiler that for the scope of the pointer declaration, the object pointed to by this pointer is only accessed through this pointer and not through any other pointer.

This allows the compiler to optimize the code, knowing that there are no aliasing issues, i.e., no other pointer will be used to access the same memory during the lifetime of the `restrict`-qualified pointer.

Here's an example:

```c
void update(int *restrict ptr1, int *restrict ptr2, int *restrict ptr3)
{
    *ptr1 += 5;
    *ptr2 += 6;
    *ptr3 += 7;
}
```

In this function, the `restrict` keyword tells the compiler that `ptr1`, `ptr2`, and `ptr3` are the only ways to access their respective objects in memory during the execution of the function. This allows the compiler to make certain optimizations it might not otherwise be able to make.

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

- [`access`](../Pipex/README.md#access): Checks the accessibility of a file.

- `open`: Opens a file or device.

- `read`: Reads data from a file or a file descriptor.

- `close`: Closes a file or a file descriptor.

- [`fork`](../Pipex/README.md#fork): Creates a new process.

- [`wait`](../Pipex/README.md#wait): Waits for a process to change state.

- [`waitpid`](../Pipex/README.md#waitpid): Waits for a specific process to change state.

- `wait3`: Waits for a child process to stop or terminate.

- `wait4`: Waits for a child process to stop or terminate, with resource usage information.

- [`signal`](#signal): Sets a function to handle a signal.

- [`sigaction`](#sigaction): Examines and changes a signal action.

- [`sigemptyset`](#sigemptyset): Initializes a signal set to empty.

- [`sigaddset`](#sigaddset): Adds a signal to a signal set.

- [`kill`](#kill): Sends a signal to a process or a group of processes.

- `exit`: Terminates the process.

- [`getcwd`](#getcwd): Gets the current working directory.

- [`chdir`](#chdir): Changes the current working directory.

- [`stat`](#stat): Gets file status.

- [`lstat`](#lstat): Like `stat`, but if the file is a symbolic link, then it returns information about the link itself, not the file it refers to.

- [`fstat`](#fstat): Like `stat`, but takes a file descriptor instead of a file name.

- [`unlink`](../Pipex/README.md#unlink): Deletes a name from the filesystem.

- [`execve`](../Pipex/README.md#execve): Executes a program.

- [`dup`](../Pipex/README.md#dup): Duplicates a file descriptor.

- [`dup2`](../Pipex/README.md#dup): Duplicates a file descriptor to a specified file descriptor.

- [`pipe`](.
- [`opendir`](#opendir): Opens a directory.

- [`readdir`](#readdir): Reads a directory.

- [`closedir`](#closedir): Closes a directory.

- [`strerror`](../Pipex/README.md#strerror): Returns a string describing an error number.

- [`perror`](../Pipex/README.md#perror): Prints a descriptive error message to stderr.

- [`isatty`](#isatty): Tests whether a file descriptor refers to a terminal.

- [`ttyname`](#ttyname): Returns the name of the terminal.

- [`ttyslot`](#ttyslot): Returns the terminal slot number.

- [`ioctl`](#ioctl): Controls device.

- [`getenv`](#getenv): Gets an environment variable.

- [`tcsetattr`](#tcsetattr): Sets the parameters associated with the terminal.

- [`tcgetattr`](#tcgetattr): Gets the parameters associated with the terminal.

- [`tgetent`](#tgetent): Loads the termcap entry for terminal.

- [`tgetflag`](#tgetflag): Returns the boolean value of capability.

- [`tgetnum`](#tgetnum): Returns the numeric value of capability.

- [`tgetstr`](#tgetstr): Returns the string value of capability.

- [`tgoto`](#tgoto): Moves the cursor to specified position.

- [`tputs`](#tputs): Applies padding information to a string and outputs it.

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

### signal

The `signal` function is a part of the C Standard Library, specifically included in the `signal.h` (or `csignal` in C++) header file. It's used to handle signals, which are software interrupts sent to a process to notify it of certain events.

Here's the function prototype:

```c
void (*signal(int signum, void (*handler)(int)))(int);
```

- `signum`: This is the signal number that you want to handle. There are several predefined signals like `SIGINT` for interrupt signal, `SIGABRT` for abort signal, etc.

- `handler`: This is a pointer to a function that takes an integer as an argument and returns void. This function will be called when the process receives the specified signal. There are also two special handlers: `SIG_IGN` and `SIG_DFL`. `SIG_IGN` tells the process to ignore the signal and `SIG_DFL` tells the process to perform the default action for the signal.

The `signal` function returns the previous handler for the signal. If an error occurs, it returns `SIG_ERR`.

<details>
  <summary>Example</summary>

Here's an example of how to use the `signal` function:

```c
#include <stdio.h>
#include <signal.h>

int signal_received = 0;

void handle_sigint(int sig) 
{ 
    printf("\nCaught signal %d\n", sig);
	signal_received++;
	printf("Signal to exit: %d\n", 3 - signal_received);
	if (signal_received == 3)
		exit(0);
} 

int main() 
{
    signal(SIGINT, handle_sigint); 
    while (1) ; 
    return 0; 
}
```

In this example, the `handle_sigint` function is set to handle the `SIGINT` signal (which is typically sent when the user presses Ctrl+C). When `SIGINT` is received, the program will print "Caught signal 2" and continue running.

</details>

Here are some common signals: (Note: The signal numbers may vary depending on the system)

| Signal Number (`signum`) | Description |
|--------------------------|-------------|
| `SIGINT`                 | Interrupt signal. This is typically sent when the user presses Ctrl+C. |
| `SIGABRT`                | Abort signal. This is sent by the `abort` function. |
| `SIGFPE`                 | Floating point exception signal. This is sent when a floating point or arithmetic error occurs. |
| `SIGILL`                 | Illegal instruction signal. This is sent when an illegal instruction is encountered. |
| `SIGSEGV`                | Segmentation fault signal. This is sent when a program accesses memory incorrectly. |
| `SIGTERM`                | Termination signal. This is sent to request the termination of a program. |

| Signal Mask (`sigmask`) | Description |
|-------------------------|-------------|
| `SIG_BLOCK`             | The set of blocked signals is the union of the current set and the set argument. |
| `SIG_UNBLOCK`           | The signals in set are removed from the current set of blocked signals. It is permissible to attempt to unblock a signal which is not blocked. |
| `SIG_SETMASK`           | The set of blocked signals is set to the argument set. |

| Signal Flags (`sigflags`) | Description |
|---------------------------|-------------|
| `SA_NOCLDSTOP`            | If signum is `SIGCHLD`, do not receive notification when child processes stop. |
| `SA_NOCLDWAIT`            | If signum is `SIGCHLD`, do not transform children into zombies when they terminate. |
| `SA_NODEFER`              | Do not prevent the signal from being received from within its own signal handler. |
| `SA_ONSTACK`              | Call the signal handler on an alternate signal stack provided by `sigaltstack`. |
| `SA_RESETHAND`            | Reset the signal handler to the default upon entry to the signal handler. |
| `SA_RESTART`              | Provide behavior compatible with BSD signal semantics by making certain system calls restartable across signals. |
| `SA_SIGINFO`              | The signal handler takes three arguments, not one. |

### sigaction

The `sigaction` function is a part of the POSIX standard and is used to change the action taken by a process on receipt of a specific signal. It's more reliable and flexible than the `signal` function.

Here's the function prototype:

```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

- `signum`: This is the signal number that you want to handle.

- `act`: This is a pointer to a `struct sigaction` which specifies the new action for the signal.

- `oldact`: This is a pointer to a `struct sigaction` where `sigaction` will store the old action for the signal. If it's NULL, the old action is not saved.

The `struct sigaction` looks like this:

```c
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};
```

- `sa_handler`: This is a pointer to a signal handling function or one of the macros `SIG_IGN` or `SIG_DFL`.

- `sa_sigaction`: This is a pointer to a signal handling function which takes three arguments, instead of one. This is used if the `SA_SIGINFO` flag is specified in `sa_flags`.

- `sa_mask`: This is a set of signals to be blocked during execution of the signal handling function.

- `sa_flags`: This is a set of flags which modify the behavior of the signal.

- `sa_restorer`: This is not used in modern systems.

<details>
  <summary>Example</summary>

Here's an example of how to use the `sigaction` function:

```c
#include <stdio.h>
#include <signal.h>

int g_signal_received = 0;

void handle_sigint(int sig)
{ 
    printf("\nCaught signal %d\n", sig);
	g_signal_received++;
	printf("Signal to exit: %d\n", 3 - g_signal_received);
	if (g_signal_received == 3)
		exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    while (1) ;
    return 0;
}
```

In this example, the `handle_sigint` function is set to handle the `SIGINT` signal (which is typically sent when the user presses Ctrl+C). When `SIGINT` is received, the program will print "Caught signal 2" and continue running.

</details>

### sigemptyset

The `sigemptyset` function is a part of the POSIX standard and is used to initialize a signal set to be empty. It's typically used in conjunction with other signal handling functions like `sigaction`.

Here's the function prototype:

```c
int sigemptyset(sigset_t *set);
```

- `set`: This is a pointer to a `sigset_t` structure that you want to initialize to empty.

The function returns 0 on success, and -1 on error.

The `sigset_t` structure is used to represent a set of signals. It's used by various signal handling functions to define a set of signals to be blocked, unblocked or waited for.


<details>
  <summary>Example</summary>
Here's an example of how to use the `sigemptyset` function:

```c
#include <stdio.h>
#include <signal.h>

int g_signal_received = 0;

void handle_sigint(int sig)
{ 
    printf("\nCaught signal %d\n", sig);
	g_signal_received++;
	printf("Signal to exit: %d\n", 3 - g_signal_received);
	if (g_signal_received == 3)
		exit(0);
}

int main() 
{ 
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask); // Initialize the mask to empty
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    while (1) ; 
    return 0; 
}
```

In this example, `sigemptyset` is used to initialize `sa.sa_mask` to be empty. This means that no signals are blocked while the `handle_sigint` function is running.

</details>

The actual implementation of `sigset_t` is not defined in the POSIX standard, and it can vary between different systems. It's typically implemented as a bit array or integer type that's large enough to support all the signals that the system provides.

Because the actual implementation of `sigset_t` is not defined, you should not manipulate `sigset_t` objects directly. Instead, you should use the functions provided by the POSIX standard to manipulate signal sets. These functions include `sigemptyset`, `sigfillset`, `sigaddset`, `sigdelset`, `sigismember`, and others.

### sigaddset

The `sigaddset` function is part of the POSIX standard and is used to add a specific signal to a signal set.

Here's the function prototype:

```c
int sigaddset(sigset_t *set, int signum);
```

- `set`: This is a pointer to a `sigset_t` structure that represents the signal set.
- `signum`: This is the signal number that you want to add to the set.

The function returns 0 on success, and -1 on error.

<details>
  <summary>Example</summary>

Here's an example of how to use the `sigaddset` function:

```c
#include <stdio.h>
#include <signal.h>

int main() 
{ 
    sigset_t set;

    // Initialize the signal set to be empty
    sigemptyset(&set);

    // Add SIGINT to the set
    sigaddset(&set, SIGBUS);

    // Check if SIGINT is in the set
    if (sigismember(&set, SIGINT)) {
        printf("SIGINT is in the set\n");
    }

	// Add SIGINT to the set
	printf("Adding SIGINT to the set\n");
	sigaddset(&set, SIGINT);

	// Check if SIGINT is in the set
	if (sigismember(&set, SIGINT)) {
		printf("SIGINT is in the set\n");
	}

    return 0; 
}
```

In this example, `sigemptyset` is used to initialize the signal set to be empty, and then `sigaddset` is used to add `SIGINT` to the set. The `sigismember` function is then used to check if `SIGINT` is in the set, and it prints "SIGINT is in the set".

</details>

### kill

The `kill` function is a part of the POSIX standard and is used to send a signal to a process or a group of processes.

Here's the function prototype:

```c
int kill(pid_t pid, int sig);
```

- `pid`: This is the process ID to which the signal is sent. There are several special values:
  - If `pid` is `> 0`, the signal is sent to the process with the ID `pid`.
  - If `pid` is `0`, the signal is sent to every process in the process group of the calling process.
  - If `pid` is `-1`, the signal is sent to every process for which the calling process has permission to send signals, except for process 1 (init), but see below.
  - If `pid` is `< -1`, the signal is sent to every process in the process group `-pid`.

- `sig`: This is the signal number that you want to send. If `sig` is 0, then no signal is sent, but error checking is still performed.

The function returns 0 on success, and -1 on error.

<details>
  <summary>Example</summary>
Here's an example of how to use the `kill` function:

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() 
{ 
    printf("Sending SIGINT to this process\n");

    // Send SIGINT to the current process
    // This will cause the process to interrupt
    kill(getpid(), SIGINT);

    return 0; 
}
```

In this example, the `kill` function is used to send the `SIGINT` signal to the current process, which causes the process to interrup. The `getpid` function is used to get the process ID of the current process.

</details>

### getcwd

The `getcwd` function is a part of the POSIX standard and is used to get the current working directory of the process.

Here's the function prototype:

```c
char *getcwd(char *buf, size_t size);
```

- `buf`: This is a pointer to a buffer where the current working directory will be stored.
- `size`: This is the size of the buffer.

The function returns a pointer to the buffer on success, and NULL on error. If the length of the absolute pathname of the current working directory, including the terminating null byte, exceeds `size` bytes, NULL is returned, and `errno` is set to `ERANGE`.

<details>
  <summary>Example</summary>
Here's an example of how to use the `getcwd` function:

```c
#include <stdio.h>
#include <unistd.h>

int main() 
{ 
    char buf[1024];

    // Get the current working directory
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("Current working directory: %s\n", buf);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0; 
} 
```

In this example, the `getcwd` function is used to get the current working directory and store it in `buf`. The current working directory is then printed to the console. If an error occurs, an error message is printed to the console.

</details>

### chdir

The `chdir` function is a part of the POSIX standard and is used to change the current working directory of the process.

Here's the function prototype:

```c
int chdir(const char *path);
```

- `path`: This is a string that specifies the path to the new working directory.

The function returns 0 on success, and -1 on error.

<details>
  <summary>Example</summary>

Here's an example of how to use the `chdir` function:

```c
#include <stdio.h>
#include <unistd.h>

int main() 
{ 
    char buf[1024];

	// Get the current working directory
	if (getcwd(buf, sizeof(buf)) != NULL) {
		printf("Current working directory: %s\n", buf);
	} else {
		perror("getcwd() error");
		return 1;
	}
	
	printf("Changing working directory to /tmp\n");
    // Change the current working directory
    if (chdir("/tmp") == 0) {
        // Get the new current working directory
        if (getcwd(buf, sizeof(buf)) != NULL) {
            printf("New working directory: %s\n", buf);
        } else {
            perror("getcwd() error");
            return 1;
        }
    } else {
        perror("chdir() error");
        return 1;
    }

    return 0; 
} 
```

In this example, the `chdir` function is used to change the current working directory to `/tmp`. The new current working directory is then retrieved with `getcwd` and printed to the console. If an error occurs, an error message is printed to the console.

</details>

### stat

The `stat` function is a part of the POSIX standard and is used to get file status information.

Here's the function prototype:

```c
int stat(const char *restrict path, struct stat *restrict buf);
```

- `path`: This is a string that specifies the path to the file.
- `buf`: This is a pointer to a `struct stat` where the file status information will be stored.

The function returns 0 on success, and -1 on error.

The `struct stat` is defined as follows:

```c
struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for file system I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
```

<details>
  <summary>Example</summary>

Here's an example of how to use the `stat` function:

```c
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{ 
    struct stat sb;

    // Get file status information
    if (stat("/tmp", &sb) == 0) {
        printf("Last status change: %s", ctime(&sb.st_ctime));
        printf("Last file access: %s", ctime(&sb.st_atime));
        printf("Last file modification: %s", ctime(&sb.st_mtime));
    } else {
        perror("stat() error");
        return 1;
    }

    return 0; 
} 
```

In this example, the `stat` function is used to get the status information of the `/tmp` directory. The times of the last status change, last access, and last modification are then printed to the console. If an error occurs, an error message is printed to the console.

</details>

### lstat

The `lstat` function is similar to `stat`, but when the named file is a symbolic link, `lstat` returns information about the link itself, not the file it refers to.

Here's the function prototype:

```c
int lstat(const char *restrict path, struct stat *restrict buf);
```

- `path`: This is a string that specifies the path to the file.
- `buf`: This is a pointer to a `struct stat` where the file status information will be stored.

The function returns 0 on success, and -1 on error.

<details>
  <summary>Example</summary>

Here's an example of how to use the `lstat` function:

```c
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{ 
    struct stat sb;

    // Get file status information
    if (lstat("/tmp/symlink", &sb) == 0) {
        printf("Last status change: %s", ctime(&sb.st_ctime));
        printf("Last file access: %s", ctime(&sb.st_atime));
        printf("Last file modification: %s", ctime(&sb.st_mtime));
    } else {
        perror("lstat() error");
        return 1;
    }

    return 0; 
}
```

In this example, the `lstat` function is used to get the status information of the `/tmp/symlink` symbolic link. The times of the last status change, last access, and last modification are then printed to the console. If an error occurs, an error message is printed to the console.

</details>

### fstat

The `fstat` function is a part of the POSIX standard and is used to get file status information about an open file.

Here's the function prototype:

```c
int fstat(int fd, struct stat *buf);
```

- `fd`: This is a file descriptor of an open file.
- `buf`: This is a pointer to a `struct stat` where the file status information will be stored.

The function returns 0 on success, and -1 on error.

<details>
  <summary>Example</summary>

Here's an example of how to use the `fstat` function:

```c
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{ 
    struct stat sb;
    int fd;

    fd = open("/tmp", O_RDONLY);
    if (fd == -1) {
        perror("open() error");
        return 1;
    }

    // Get file status information
    if (fstat(fd, &sb) == 0) {
        printf("File size: %lld bytes\n", (long long) sb.st_size);
    } else {
        perror("fstat() error");
        return 1;
    }

    close(fd);
    return 0; 
} 
```

In this example, the `fstat` function is used to get the status information of the file opened with the `open` function. The size of the file is then printed to the console. If an error occurs, an error message is printed to the console.

</details>

### opendir

The `opendir` function is a part of the POSIX standard and is used to open a directory stream corresponding to a given directory, so that the contents of the directory can be retrieved.

Here's the function prototype:

```c
DIR* opendir(const char *name);
```

- `name`: This is a string representing the path to the directory.

The function returns a pointer to a `DIR` structure representing the directory stream. If an error occurs (for example, if the directory does not exist), `opendir` returns `NULL`.

<details>
  <summary>Example</summary>

Here's an example of how to use the `opendir` function:

```c
#include <dirent.h>

int main() 
{ 
    DIR* dir = opendir("/path/to/directory");
    if (dir == NULL) {
        perror("opendir() error");
        return 1;
    }

    // Use the directory stream...
    // Don't forget to close it when you're done
    closedir(dir);

    return 0; 
} 
```

In this example, the `opendir` function is used to open a directory stream for the directory at `/path/to/directory`. If the directory stream is successfully opened, `opendir` returns a pointer to a `DIR` structure representing the directory stream. If an error occurs, an error message is printed to the console.

</details>

#### DIR structure

The `DIR` structure represents a directory stream in the C programming language. It's defined in the `dirent.h` header file. However, the exact contents of the `DIR` structure are not defined in the POSIX standard, and they can vary between different operating systems and C libraries.

Because of this, you generally shouldn't need to access the members of the `DIR` structure directly. Instead, you should use the functions provided by the `dirent.h` header file, such as `opendir`, `readdir`, and `closedir`, to work with directory streams.

<details>
  <summary>Example</summary>

Here's an example of how you might use these functions to read the contents of a directory:

```c
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/home/");
    if (dir == NULL) {
        perror("opendir() error");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
```

In this example, `opendir` is used to open a directory stream, `readdir` is used to read the entries in the directory, and `closedir` is used to close the directory stream when we're done with it. The `d_name` member of the `struct dirent` structure represents the name of the directory entry.

</details>

### readdir

The `readdir` function is a part of the `dirent.h` library in C and is used to read a directory entry from a directory stream. It allows you to retrieve the contents of the directory.

Here's the function prototype:

```c
struct dirent* readdir(DIR *dirp);
```

- `dirp`: This is a pointer to a `DIR` structure representing the directory stream.

The function returns a pointer to a `dirent` structure representing the next directory entry in the directory stream. If there are no more entries to read, or if an error occurs, `readdir` returns `NULL`.

<details>
  <summary>Example</summary>

Here's an example of how to use the `readdir` function:

```c
#include <dirent.h>

int main() 
{ 
    DIR* dir = opendir("/path/to/directory");
    if (dir == NULL) {
        perror("opendir() error");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Don't forget to close the directory stream when you're done
    closedir(dir);

    return 0; 
} 
```

In this example, the `readdir` function is used to read all the entries in the directory at `/path/to/directory`. For each entry, the name of the entry is printed to the console. If an error occurs, an error message is printed to the console.

</details>

### closedir

The `closedir` function is a part of the `dirent.h` library in C and is used to close a directory stream that was previously opened by `opendir`. It's important to close directory streams when you're done with them to free up system resources.

Here's the function prototype:

```c
int closedir(DIR *dirp);
```

- `dirp`: This is a pointer to a `DIR` structure representing the directory stream.

The function returns 0 on success. If an error occurs, `closedir` returns -1.

<details>
  <summary>Example</summary>

Here's an example of how to use the `closedir` function:

```c
#include <dirent.h>

int main() 
{ 
    DIR* dir = opendir("/path/to/directory");
    if (dir == NULL) {
        perror("opendir() error");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory stream
    if (closedir(dir) == -1) {
        perror("closedir() error");
        return 1;
    }

    return 0; 
} 
```

In this example, the `closedir` function is used to close the directory stream for the directory at `/path/to/directory` after all the entries have been read. If the directory stream is successfully closed, `closedir` returns 0. If an error occurs, an error message is printed to the console.

</details>

### isatty

The `isatty` function is a part of the `unistd.h` library in C and is used to check if a file descriptor refers to a terminal.

Here's the function prototype:

```c
int isatty(int fd);
```

- `fd`: This is the file descriptor that you want to check.

The function returns 1 if `fd` refers to a terminal, and 0 if it does not. If an error occurs, `isatty` returns 0 and sets `errno` to indicate the error.

<details>
  <summary>Example</summary>

Here's an example of how to use the `isatty` function:

```c
#include <unistd.h>
#include <stdio.h>

int main() 
{ 
    if (isatty(STDOUT_FILENO)) {
        printf("STDOUT is a terminal.\n");
    } else {
        printf("STDOUT is not a terminal.\n");
    }

    return 0; 
}
```

In this example, the `isatty` function is used to check if the standard output (STDOUT) is a terminal. If STDOUT is a terminal, a message is printed to the console indicating this. If STDOUT is not a terminal, a different message is printed.

</details>

#### TTY (Teletypewriter)

A TTY (Teletypewriter) is a terminal device in computing which provides text-based communication between machines. It was originally designed to send and receive typed messages without the need for a human operator.

In modern computing, the term "TTY" is often used to refer to any terminal, including virtual terminals provided by software, not just physical teletypewriter machines. For example, when you open a terminal window on a Unix-like operating system, you're using a TTY.

The `isatty` function in C checks if a given file descriptor refers to a terminal (TTY), which can be useful to determine if your program is being run interactively or is being redirected to a file or piped to another program.

### ttyname

The `ttyname` function is a part of the `unistd.h` library in C and is used to get the name of the terminal associated with a given file descriptor.

Here's the function prototype:

```c
char *ttyname(int fd);
```

- `fd`: This is the file descriptor that you want to get the terminal name for.

The function returns a pointer to a string containing the name of the terminal. If `fd` is not associated with a terminal, or if an error occurs, `ttyname` returns `NULL`.

<details>
  <summary>Example</summary>

Here's an example of how to use the `ttyname` function:

```c
#include <unistd.h>
#include <stdio.h>

int main() 
{ 
    char *name = ttyname(STDOUT_FILENO);
    if (name == NULL) {
        perror("ttyname() error");
        return 1;
    }

    printf("The terminal name for STDOUT is: %s\n", name);

    return 0;
} 
```

In this example, the `ttyname` function is used to get the name of the terminal associated with the standard output (STDOUT). If STDOUT is associated with a terminal, the name of the terminal is printed to the console. If STDOUT is not associated with a terminal, or if an error occurs, an error message is printed to the console.

</details>

### ttyslot

The `ttyslot` function is a part of the `unistd.h` library in C and is used to get the index of the current process's controlling terminal in the system's list of terminals.

Here's the function prototype:

```c
int ttyslot(void);
```

The function does not take any arguments.

The function returns the index of the current process's controlling terminal in the system's list of terminals. If the current process does not have a controlling terminal, or if an error occurs, `ttyslot` returns 0.

<details>
  <summary>Example</summary>

Here's an example of how to use the `ttyslot` function:

```c
#include <unistd.h>
#include <stdio.h>

int main() 
{ 
    int slot = ttyslot();
    if (slot == 0) {
        perror("ttyslot() error");
        return 1;
    }

    printf("The terminal slot for this process is: %d\n", slot);

    return 0; 
} 
```

In this example, the `ttyslot` function is used to get the index of the current process's controlling terminal in the system's list of terminals. If the current process has a controlling terminal, the index of the terminal is printed to the console. If the current process does not have a controlling terminal, or if an error occurs, an error message is printed to the console.

</details>


### ioctl

`ioctl` stands for "input-output control". It's a kind of catch-all system call in Unix and Unix-like operating systems. It provides a way for a program to interact with a device driver, allowing it to configure hardware, control it, or otherwise communicate with it.

The `ioctl` function has three arguments: a file descriptor, a request code, and a pointer to memory. The file descriptor is typically obtained from opening a device file, the request code is specific to the device driver and operation, and the pointer to memory is used to transfer data between the program and the device driver.

The `ioctl` function is a part of the `sys/ioctl.h` library in C and is used to control device parameters of special files. In particular, many operating characteristics of character special files (e.g., terminals) may be controlled with `ioctl` requests.

Here's the function prototype:

```c
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
```

The function takes a file descriptor `fd` that is obtained from opening a device file, a device-dependent `request` code, and optionally additional arguments depending on the request.

The function returns 0 on success. On error, -1 is returned, and `errno` is set appropriately.

<details>
  <summary>Example</summary>

Here's an example of how to use the `ioctl` function:

```c
#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{ 
    int fd = open("/dev/mydevice", O_RDWR);
    if (fd == -1) {
        perror("open() error");
        return 1;
    }

    int result = ioctl(fd, MYDEVICE_IOCTL_COMMAND, NULL);
    if (result == -1) {
        perror("ioctl() error");
        close(fd);
        return 1;
    }

    printf("The ioctl command was successful.\n");

    close(fd);
    return 0; 
} 
```

In this example, the `ioctl` function is used to send a command to a device. The device is opened with `open`, and then the `ioctl` command is sent. If the `ioctl` command is successful, a success message is printed to the console. If an error occurs, an error message is printed to the console and the device is closed.

Please note that `MYDEVICE_IOCTL_COMMAND` is a placeholder for a real ioctl command and `/dev/mydevice` is a placeholder for a real device file. Always refer to the specific device's documentation for correct usage.

</details>

### getenv

`getenv` stands for "get environment". It's a function in Unix and Unix-like operating systems that retrieves the value of an environment variable from the process's environment.


The `getenv` function is a part of the `stdlib.h` or `cstdlib` library in C and C++ and is used to access environment variables.

Here's the function prototype:

```c
#include <stdlib.h>

char* getenv(const char* name);
```

* The function takes a string `name` as an argument, which is the name of the environment variable you want to retrieve.
* The function returns a pointer to a string which is the value of the environment variable. If the requested environment variable is not found, it returns a null pointer.

<details>
  <summary>Example</summary>

Here's an example of how to use the `getenv` function:

```c
#include <stdlib.h>
#include <stdio.h>

int main() 
{ 
    char* path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
    } else {
        printf("PATH = %s\n", path);
    }

    return 0; 
} 
```

In this example, the `getenv` function is used to retrieve the value of the `PATH` environment variable. If the `PATH` environment variable is found, its value is printed to the console. If it is not found, an error message is printed.

</details>

### tcsetattr

`tcsetattr` is a function in Unix and Unix-like operating systems that is used to change the parameters of a terminal device. It's part of the termios library, which provides terminal I/O interfaces.

Here's the function prototype in C:

```c
#include <termios.h>

int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
```

* `fd`: This is the file descriptor of the terminal. Usually, standard input (`STDIN_FILENO`) is used.
* `optional_actions`: This specifies when the changes should take effect. It can be one of the following:
  * `TCSANOW`: changes occur immediately.
  * `TCSADRAIN`: changes occur after all output written to `fd` has been transmitted.
  * `TCSAFLUSH`: changes occur after all output written to `fd` has been transmitted, and all input that has been received but not read will be discarded before the change is made.
* `termios_p`: This is a pointer to a `termios` structure that contains the new terminal parameters.

The function returns 0 on success, and -1 on failure. In case of failure, `errno` is set appropriately.

<details>
  <summary>Example</summary>
Here's an example of how to use the `tcsetattr` function:

```c
#include <stdio.h>
#include <termios.h>
#include <unistd.h>


// Define STDIN_FILENO if it's not defined
#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif /* STDIN_FILENO */

int main() {
    struct termios original, noecho;

	// Code that need to be executed before the noecho flag
	printf("Enter the password: ");
	char password_show[64];
	scanf("%s", password_show);
	printf("\nYou entered: %s\n", password_show);
    
    // Obtain the current terminal configuration
    tcgetattr(STDIN_FILENO, &original);
    
    // Duplicate the current configuration
    noecho = original;
    
    // Turn off the ECHO flag
    noecho.c_lflag &= ~ECHO;
    
    // Set the terminal to the modified configuration
    tcsetattr(STDIN_FILENO, TCSANOW, &noecho);
    
	printf("\nAfter applying the noecho flag\n");
	
    // Your code here that requires no echo
	printf("Enter the password: ");
	char password[64];
	scanf("%s", password);
	printf("\nYou entered: %s\n", password);
    
    // Restore the original terminal configuration
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
    
    return 0;
}
```

In this example, the `tcsetattr` function is used to turn off echoing of input characters.

</details>

#### termios structure

The `termios` structure is used to hold terminal I/O settings in Unix and Unix-like operating systems. It's defined in the `<termios.h>` header file.

Here's what the `termios` structure looks like in C:

```c
struct termios {
    tcflag_t c_iflag;  /* input modes */
    tcflag_t c_oflag;  /* output modes */
    tcflag_t c_cflag;  /* control modes */
    tcflag_t c_lflag;  /* local modes */
    cc_t c_cc[NCCS];   /* control characters */
};
```

Here's a brief description of each field:

* `c_iflag`: This field contains the input modes. It's a bitmask that can include flags like `IGNBRK` (ignore break condition), `ICRNL` (map CR to NL on input), `IXON` (enable XON/XOFF flow control on output), and others.

* `c_oflag`: This field contains the output modes. It's a bitmask that can include flags like `OPOST` (perform post-processing of output), `ONLCR` (map NL to CR-NL on output), and others.

* `c_cflag`: This field contains the control modes. It's a bitmask that can include flags like `CSIZE` (character size), `PARENB` (parity enable), `CSTOPB` (two stop bits, otherwise one), and others.

* `c_lflag`: This field contains the local modes. It's a bitmask that can include flags like `ECHO` (echo input characters), `ICANON` (canonical mode enable), `ISIG` (signal characters enable), and others.

* `c_cc`: This field contains an array of control characters. It includes characters like `VEOF` (end-of-file character), `VINTR` (interrupt character), `VERASE` (erase character), and others. The size of the array is defined by `NCCS`.

### tcgetattr

`tcgetattr` is a function in Unix and Unix-like operating systems that is used to get the parameters of a terminal device. It's part of the termios library, which provides terminal I/O interfaces.

Here's the function prototype in C:

```c
#include <termios.h>

int tcgetattr(int fd, struct termios *termios_p);
```

* `fd`: This is the file descriptor of the terminal. Usually, standard input (`STDIN_FILENO`) is used.
* `termios_p`: This is a pointer to a `termios` structure where the function will store the terminal parameters.

The function returns 0 on success, and -1 on failure. In case of failure, `errno` is set appropriately.

<details>
  <summary>Example</summary>
Here's an example of how to use the `tcgetattr` function:

```c
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Define STDIN_FILENO if it's not defined
#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif /* STDIN_FILENO */

int main() {
    struct termios original;

    // Obtain the current terminal configuration
    if(tcgetattr(STDIN_FILENO, &original) == -1) {
        perror("tcgetattr");
        return -1;
    }

    // Your code here that requires the terminal configuration

    return 0;
}
```

In this example, the `tcgetattr` function is used to get the current terminal configuration.

</details>

### tgetent

`tgetent` is a function in Unix and Unix-like operating systems that is used to fetch a termcap entry for a terminal. It's part of the termcap library, which provides a way to handle different terminals in a uniform way.

Here's the function prototype in C:

```c
#include <termcap.h>

int tgetent(char *bp, const char *name);
```

* `bp`: This is a pointer to a buffer where the termcap entry will be stored. The buffer should be large enough to hold the entry. A size of 1024 bytes is often used.
* `name`: This is the name of the terminal for which the termcap entry should be fetched.

The function returns 1 if the termcap entry was found, 0 if it was not found, and -1 if there was an error (for example, if the termcap database could not be opened).

#### Using termcap

To use the `tgetent` function in your C program, you need to link against the termcap library. This is done by adding `-ltermcap` to your gcc or cc command.

Here's an example of how you can compile your program:

```shell
gcc -o myprogram main.c -ltermcap
```

In this command, myprogram is the name of the output file, main.c is your source file, and -ltermcap tells the compiler to link against the termcap library.

<details>
  <summary>Example</summary>

Here's an example of how to use the `tgetent` function:

```c
#include <stdio.h>
#include <termcap.h>
#include <stdlib.h>

int main() {
    const char *name;
    char *bp;
    char *term;
    int height;
    int width;

    bp = malloc(sizeof(*bp));
    name = "TERM";
    if ((term = getenv(name)) == NULL)
        return (1);
    printf("My terminal is %s.\n", term);
    tgetent(bp, term);
    height = tgetnum("li");
    width = tgetnum("co");
    printf("Height: %d\nWidth: %d\n", height, width);
    free(bp);
    return (0);
}
```

In this example, the `tgetent()` function is used to load the terminal capabilities for the terminal type specified by the `TERM `environment variable. The height and width of the terminal are then retrieved using `tgetnum()` and printed out

</details>

#### Termcap

Termcap (Terminal Capability) is a software library and database used on Unix-like systems for enabling the system to correctly display interfaces on different types of terminals. Each entry in the termcap database, typically found in the file `/etc/termcap`, represents the capabilities of a certain terminal, or a class of terminals.

Termcap provides a way for applications to use terminal capabilities abstractly, so they can work with many different types of terminals without having to know the specific details of each one. It provides information about the terminal's capabilities, such as the number of columns and rows, whether it can display colors, how to move the cursor, etc.

The termcap library provides functions to query the termcap database, like `tgetent` to get an entry for a specific terminal, `tgetnum` to get a numeric terminal capability, `tgetflag` to get a boolean terminal capability, and `tgetstr` to get a string terminal capability.

### tgetflag

`tgetflag` is a function in Unix and Unix-like operating systems that is used to get a boolean capability from a termcap entry. It's part of the termcap library, which provides a way to handle different terminals in a uniform way.

Here's the function prototype in C:

```c
#include <termcap.h>

int tgetflag(char *id);
```

* `id`: This is a two-letter identifier for the capability.

The function returns 1 if the terminal has the capability, and 0 if it does not. If the capability is not a boolean capability, or if the termcap entry has not been loaded with `tgetent`, the result is undefined.

<details>
  <summary>Example</summary>
Here's an example of how to use the `tgetflag` function:

```c
#include <stdio.h>
#include <termcap.h>

int main() {
    char term_buffer[1024];
    char *term_type = "xterm";

    if(tgetent(term_buffer, term_type) != 1) {
        fprintf(stderr, "Could not get termcap entry for %s\n", term_type);
        return -1;
    }

    if(tgetflag("am")) {
        printf("The terminal has automatic margins.\n");
    } else {
        printf("The terminal does not have automatic margins.\n");
    }

    return 0;
}
```

In this example, the `tgetflag` function is used to check if the terminal has the "am" (automatic margins) capability.

</details>

Here's a table of some common two-letter identifiers (ids) that can be used with `tgetflag` to get boolean capabilities:

| ID  | Description |
| --- | ----------- |
| `am` | Terminal has automatic margins |
| `bs` | Terminal can backspace |
| `bw` | Terminal can backspace to previous line |
| `da` | Terminal can insert/delete lines |
| `db` | Terminal can insert/delete characters |
| `eo` | Can erase overstrikes with a blank |
| `gn` | Generic line type |
| `hc` | Hardcopy terminal |
| `hz` | Hazardous for motion |
| `in` | Terminal can insert characters |
| `mi` | Safe to move while in insert mode |
| `ms` | Safe to move while in standout mode |
| `nc` | No correctable delay |
| `os` | Terminal can overstrike |
| `ul` | Terminal can underline |
| `xs` | Standout not erased by overwriting |
| `xt` | Tabs destructive, magic so char (T1061) |

Please note that not all terminals define all capabilities, and the actual capabilities available depend on the specific terminal and its termcap entry.

### tgetnum

`tgetnum` is a function in Unix and Unix-like operating systems that is used to get a numeric capability from a termcap entry. It's part of the termcap library, which provides a way to handle different terminals in a uniform way.

Here's the function prototype in C:

```c
#include <termcap.h>

int tgetnum(char *id);
```

* `id`: This is a two-letter identifier for the capability.

The function returns the numeric value of the capability if it is defined. If the capability is not a numeric capability, or if the termcap entry has not been loaded with `tgetent`, the result is undefined.

<details>
  <summary>Example</summary>
Here's an example of how to use the `tgetnum` function:

```c
#include <stdio.h>
#include <termcap.h>

int main() {
    char term_buffer[1024];
    char *term_type = "xterm";

    if(tgetent(term_buffer, term_type) != 1) {
        fprintf(stderr, "Could not get termcap entry for %s\n", term_type);
        return -1;
    }

    int cols = tgetnum("co");
    if(cols != -1) {
        printf("The terminal has %d columns.\n", cols);
    } else {
        printf("The number of columns is not defined.\n");
    }

    return 0;
}
```

In this example, the `tgetnum` function is used to get the number of columns ("co") capability of the terminal.

</details>

Here's a table of some common two-letter identifiers (ids) that can be used with `tgetnum` to get numeric capabilities:

| ID  | Description |
| --- | ----------- |
| `co` | Number of columns |
| `li` | Number of lines |
| `sg` | Number of magic cookies left by standout mode |
| `ug` | Number of magic cookies left by underline mode |
| `ws` | Width in characters of the terminal's status line |
| `lw` | Number of lines per screen or page |
| `tw` | Width of the terminal in characters |
| `kn` | Number of function keys the terminal has |
| `Wc` | Wait time for carriage return |
| `pb` | Lowest baud rate where padding needed |
| `NC` | No correctable delay |
| `dB` | Milliseconds of delay needed for backspace |
| `dC` | Milliseconds of delay needed for carriage return |
| `dN` | Milliseconds of delay needed for newline |
| `dT` | Milliseconds of delay needed for horizontal tab |
| `dV` | Milliseconds of delay needed for vertical tab |

Please note that not all terminals define all capabilities, and the actual capabilities available depend on the specific terminal and its termcap entry.

### tgetstr

`tgetstr` stands for "get string". It's a function in Unix and Unix-like operating systems that retrieves a string capability from the terminal database.

The `tgetstr` function is a part of the `termcap.h` library in C.
Here's the function prototype:

```c
#include <term.h>

char* tgetstr(char* id, char** area);
```

* The function takes two arguments: 
  * a string `id` which is the name of the terminal capability you want to retrieve
  * a pointer to a buffer `area` where the resulting string will be placed.
* The function returns a pointer to a string which is the value of the terminal capability. If the requested terminal capability is not found, it returns a null pointer.

<details>
  <summary>Example</summary>

Here's an example of how to use the `tgetstr` function:

```c
#include <termcap.h>
#include <stdlib.h>

#define MAXTERM 1024
#define MAXENTRY 512


char bp[MAXTERM];
char *area;

int main() {
    char *tgetstr();
    char *p, *q;

    p = getenv("TERM");
    tgetent(bp,p);
    q = area;
    p = tgetstr("cl",&q);
    if (p == NULL) {
        printf("Clear screen capability not found.\n");
    } else {
        tputs(p, 1, putchar);
    }

    return 0;
}
```

In this example, the `tgetstr` function is used to retrieve the "cl" (clear screen) terminal capability. The resulting string is then output to the terminal using `tputs`.

</details>

The `tgetstr` function requires a buffer to store the string representation of the terminal capability. The size of this buffer is not strictly defined, but it should be large enough to hold the longest possible terminal capability string. 

A common practice is to allocate a buffer of 1024 bytes, which should be more than enough for any terminal capability string. 

Here's how you can modify your code:

```c
// Assume term_buffer contains the terminal description obtained from tgetent
term_buffer = malloc(sizeof(char) * 1024); // Initialize term_buffer appropriately

// Allocate space for the buffer
buffer = malloc(1024);
if (!buffer) {
    // Handle allocation failure
    exit(EXIT_FAILURE);
}
```

Remember to check the return value of `malloc` to ensure that the memory allocation was successful. If `malloc` returns `NULL`, it means that the memory allocation failed and you should handle this error appropriately.

Here's a table of some common terminal capability names (ids) that can be used with `tgetstr`:

| ID  | Description |
| --- | ----------- |
| `cl` | Clear the screen and home the cursor |
| `cm` | Move the cursor to a specified position |
| `ce` | Clear to the end of the line |
| `cd` | Clear to the end of the screen |
| `so` | Start standout mode |
| `se` | End standout mode |
| `us` | Start underline mode |
| `ue` | End underline mode |
| `mb` | Start blinking mode |
| `md` | Start bold mode |
| `mr` | Start reverse mode |
| `me` | End all attribute modes |
| `ks` | Start keypad transmit mode |
| `ke` | End keypad transmit mode |
| `ti` | Start "cursor addressing" mode |
| `te` | End "cursor addressing" mode |

Please note that not all terminals define all capabilities, and the actual capabilities available depend on the specific terminal and its termcap entry.

### tgoto

`tgoto` is a function in the termcap library, which is used for terminal handling in Unix-like operating systems.

The `tgoto` function is used to generate a cursor addressing string. It takes three arguments: the cursor motion string (obtained from `tgetstr`), and the destination column and row.

Here's the function prototype:

```c
#include <term.h>

char* tgoto(const char* cap, int col, int row);
```

* `cap` is the cursor motion string, usually obtained from `tgetstr("cm", &buffer)`.
* `col` is the destination column.
* `row` is the destination row.

The function returns a pointer to a string which can be used to move the cursor to the specified position. If the cursor motion string is not valid, it returns a pointer to an error message.

<details>
  <summary>Example</summary>

Here's an example of how to use the `tgoto` function:

```c
#include <termcap.h>
#include <stdlib.h>

char bp[1024];
char *area;

int main() {
    char *tgetstr();
    char *p, *q;

    p = getenv("TERM");
    tgetent(bp,p);
    q = area;
    p = tgetstr("cm",&q);
    if (p == NULL) {
        printf("Cursor motion capability not found.\n");
    } else {
        char* cursor_move = tgoto(p, 25, 20);
        tputs(cursor_move, 1, putchar);
    }

	// printf at 25 column, 20 row
	printf("Input moved to 25, 20:");
	char str[64];
	scanf("%s", str);

	// printf at normal position
	printf("You entered: %s\n", str);
	
    return 0;
}
```

In this example, the `tgetstr` function is used to retrieve the "cm" (cursor motion) terminal capability. The `tgoto` function is then used to generate a string that moves the cursor to the position (10, 5). This string is output to the terminal using `tputs`.

</details>

### tputs

`tputs` is a function in the termcap library, which is used for terminal handling in Unix-like operating systems.

The `tputs` function is used to output a string to the terminal. It takes three arguments: the string to output, an integer indicating the number of lines affected by the output, and a pointer to an output function.

Here's the function prototype:

```c
#include <term.h>

int tputs(const char* str, int affcnt, int (*putc)(int));
```

* `str` is the string to output.
* `affcnt` is the number of lines affected by the output. This is used to add padding characters if necessary.
* `putc` is a pointer to an output function. This function is called to output each character of the string.

The function returns an integer. If it completes successfully, it returns OK. If an error occurs, it returns ERR.

<details>
  <summary>Example</summary>

Here's an example of how to use the `tputs` function:

```c
#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>

char bp[1024];
char *area;

int main() {
    char *tgetstr();
    char *p, *q;

    p = getenv("TERM");
    tgetent(bp,p);
    q = area;
    p = tgetstr("cl",&q);

	printf("Input 1 to clear the screen using tputs(): ");
	int input;
	scanf("%d", &input);
	if (input == 1) {
		if (p == NULL) {
			printf("Clear screen capability not found.\n");
		} else {
			tputs(p, 1, putchar);
		}
	}

    return 0;
}
```

In this example, the `tgetstr` function is used to retrieve the "cl" (clear screen) terminal capability. The resulting string is then output to the terminal using `tputs`.

</details>
