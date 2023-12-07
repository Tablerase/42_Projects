# Makefile

## Make

- **`-C`** `/path/to/directory` :
  - make changes to the directory /path/to/directory before it starts reading the makefiles. This is useful when you want to build a project that resides in a different directory, but you're currently in a different directory.

- **`-L`** `/path/to/libraries` :
  - commonly used to specify a directory where the linker should search for libraries. When compiling a program, the linker needs to find the necessary libraries that the program depends on. By using the `-L` option followed by a directory path, you are telling the linker to search for libraries in that specific directory.
  - For example, if you have a library called `libexample.a` located in the directory `/path/to/libraries`, you can use the `-L` option to specify that directory.

## Hide/Silence outputs and echos

- **`@`** `cmd` :
  - symbol is often used as a prefix to a command or recipe to suppress the echoing of that command during the build process. Instructing the Makefile to execute the command silently, without displaying the command itself in the output. This can be useful to reduce noise and make the build output cleaner and more focused.
  
   ```makefile
   target:
   @echo "Building target..."
   @gcc -o target source.c
   ```

  - `@` symbol and the `.SILENT` target **only suppress the echo of the command invocations**, not the output of the commands.

- **`--silent`** or **`-s`** :
  - silence the command invocations of every target.

  ```shell
  make -sC /path/to/another/makefile
  ```

- To **hide completely the output** send *stderr and stdout* to *dev/null*
  - Only stdout : ```command 1>/dev/null```
  - Only stderr : ```command 2>/dev/null```

  - Both

  ```shell
  command >/dev/null 2>&1
  ```

  ```makefile
  mlx_setup:
      @git clone https://github.com/42Paris/minilibx-linux.git mlx > /dev/null 2>&1
      @make -sC $(MLX) > /dev/null 2>&1
  ```

## Variables

- **`$@`** represents the **target** of the rule. If the target is an archive member, then `$@` is the name of the archive file. In a pattern rule that has multiple targets, `$@` is the name of whichever target caused the rule's recipe to be run.

- **`$<`** represents the name of the **first prerequisite**. If the target got its recipe from an implicit rule, this will be the first prerequisite added by the implicit rule.

- **`$^`** represents **all the prerequisites of the target, separated by spaces**. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.

- **`$*`** represents the **stem of the target filename**. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged

## Shell commands

To run the **shell** command, it has to be within the brackets and prefixed with shell. 

- Example: `$(shell uname)`

Conditions:

- `-d` : Check if directory exist

  ```makefile
  if [ -d "/path/to/directory" ]; then
    echo "Directory exists"
  else
    echo "Directory does not exist"
  fi
  ```

## Colors

We can use ANSII code to color the output of our makefile.

```makefile
GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
PURPLE = \033[0;35m
RESET = \033[0m
```

```makefile
echo "$(GREEN)MiniLibX Installed$(RESET)"
```
