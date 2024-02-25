# Makefile

## Make

- **`-C`** `/path/to/directory` :
  - make changes to the directory /path/to/directory before it starts reading the makefiles. This is useful when you want to build a project that resides in a different directory, but you're currently in a different directory.

- **`-L`** `/path/to/libraries` :
  - commonly used to specify a directory where the linker should search for libraries. When compiling a program, the linker needs to find the necessary libraries that the program depends on. By using the `-L` option followed by a directory path, you are telling the linker to search for libraries in that specific directory.
  - For example, if you have a library called `libexample.a` located in the directory `/path/to/libraries`, you can use the `-L` option to specify that directory.

## Target

- target:
  - The target is the name of the file that is to be made. It is the first item in the rule. If it is a file that must be made, the commands associated with it are executed. If the target file does not exist, or if any of the files that the target depends on have been changed more recently than the target file, the commands are executed.

    ```makefile
    TARGET = prerequisite1.o
    ```

- prerequisites:
  - The prerequisites are the files that the target depends on. A target often depends on several files. If any of the prerequisites have been changed more recently than the target, the commands are executed.

- target_rule
  - The target rule is the sequence of commands that are executed to produce the target. The target rule is the part of the rule that follows the target and prerequisites. It is a sequence of commands that are executed to produce the target. The target rule is often called the recipe.

  ```makefile
  $(TARGET): 
      $(CC) $(CFLAGS) -c prerequisite1.c
  ```


- **`all`** :
  - The `all` target is often used as the default target in a Makefile. When you run `make` without specifying a target, the `all` target is executed. The `all` target is used to specify a sequence of commands that should be executed when the `make` command is run without specifying a target.

  ```makefile
  all: target1 target2
  ```

- **`.PHONY`** :
  - The `.PHONY` target is used to declare a target as a phony target. A phony target is a target that is not a real file. It is used to specify a sequence of commands that should be executed when the target is specified. The `.PHONY` target is often used to declare targets that are not real files, such as `clean` or `all`.

  ```makefile
  .PHONY: clean
  clean:
      rm -f *.o
  ```

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

## Example

- Example of a Makefile for a C project with Libft at 42 School:

```makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:51:05 by rcutte            #+#    #+#              #
#    Updated: 2024/02/06 17:28:00 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################### Program ######################

NAME = program

all: $(NAME)

####################### FLAGS #######################

CC = cc
CFLAGS = -Wextra -Wall -Werror -g3
READLINE = -lreadline
TERMCAP = -ltermcap

ADD_FLAGS = $(READLINE) $(TERMCAP)

###################### Libft ########################

LIB_PATH = ./libft
LIB_Includes = ./libft/Includes
LIBFT = $(LIB_PATH)/libft.a

$(LIBFT):
	make -sC $(LIB_PATH)
	@if [ -f $(LIB_PATH)/libft.a ]; then \
		echo "$(ARCHIVED)\
╭──────────────────────────────────────────────────╮\n\
│                    Libft Created                 │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi
	
lib_clean:
	@if [ -f $(LIB_PATH)/Libft/ft_tolower.o ]; then \
		make -sC $(LIB_PATH) clean; \
		echo "$(ORANGE)Libft Objects Cleaned$(RESET)"; \
	fi

lib_fclean:
	@if [ -f $(LIB_PATH)/libft.a ]; then \
		make -sC $(LIB_PATH) fclean; \
		echo "$(ORANGE)Libft Library Delete$(RESET)"; \
	fi

###################### Mandatory ########################

# header path
INCLUDES = ./Includes
# source path
SRC_PATH = ./Sources/mandatory

# files
SRC = main.c \

# objet libft
OBJ = $(addprefix $(SRC_PATH)/,$(SRC:.c=.o))

###################### Bonus ########################

NAME_BONUS = program_bonus
SRC_BONUS_PATH = ./Sources/bonus
SRC_BONUS = main_bonus.c \

OBJ_BONUS = $(addprefix $(SRC_BONUS_PATH)/,$(SRC_BONUS:.c=.o))

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(ADD_FLAGS) -o $(NAME_BONUS)
	@if [ -f $(NAME_BONUS) ]; then \
		echo "$(COMPILED)\
╭──────────────────────────────────────────────────╮\n\
│             🌟 Program Bonus Compiled 🌟         │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi
	@if [ ! -f $(NAME_BONUS) ]; then \
		@echo "$(FAILED)\
╭──────────────────────────────────────────────────╮\n\
│         Program Bonus Compilation Failed         │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi

bonus: $(NAME_BONUS)

rebonus: re_msg fclean bonus

##################### Commands ######################

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(ADD_FLAGS) -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(COMPILED)\
╭──────────────────────────────────────────────────╮\n\
│                  Program Compiled                │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi
	@if [ ! -f $(NAME) ]; then \
		echo "$(RED)$(RESET)"; \
		@echo "$(FAILED)\
╭──────────────────────────────────────────────────╮\n\
│            Program Compilation Failed            │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi

%.o : %.c
	$(CC) -c $(CFLAGS) -I$(INCLUDES) -I$(LIB_Includes) -o $@ $<

clean: clean_msg lib_clean
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean lib_fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	
re: re_msg fclean all

####################### Tests ########################

ARGS = 

exec: all exec_msg
	@./$(NAME) $(ARGS)

ARGS_BONUS = 

exec_bonus: bonus exec_msg
	@./$(NAME_BONUS) $(ARGS_BONUS)

###################### Valgrind/Debug ######################

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
 --trace-children=yes --track-fds=yes \
	./$(NAME) $(ARGS)

valgrind_bonus: bonus
	@valgrind --leak-check=full --show-leak-kinds=all -s \
 --trace-children=yes --track-fds=yes --track-origins=yes \
	./$(NAME_BONUS) $(ARGS_BONUS)

lldb: all
	@lldb ./$(NAME) $(ARGS)

lldb_bonus: bonus
	@lldb ./$(NAME_BONUS) $(ARGS_BONUS)

################### Special Target ###################

.PHONY: all clean fclean re \
	bonus rebonus exec exec_bonus valgrind \
	lib_clean lib_fclean lldb lldb_bonus

.SILENT: $(NAME) $(OBJ) $(OBJ_BONUS) $(LIBFT) bonus

###################### Messages ######################
compile_msg:
	@echo "$(COMPILED)\
	╭──────────────────────────────────────────────────╮\n\
	│                  Program Compiled                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

clean_msg:
	@echo "$(GREY)\
	╭──────────────────────────────────────────────────╮\n\
	│                  Cleaning Objects                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

re_msg:
	@echo "$(PROGRAM)\
	╭──────────────────────────────────────────────────╮\n\
	│     🚧 Recreation of Program and Libraries 🚧    │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

exec_msg:
	@echo "$(EXEC)\
	╭──────────────────────────────────────────────────╮\n\
	│                 Executing Program                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

###################### Colors #######################

# ANSI escape codes for colors and formatting
# Format: \033[<attribute>;<foreground>;<background>m

EXEC = \033[1;94m
PROGRAM = \033[1;95m
COMPILED = \033[1;92m
ARCHIVED = \033[1;93m
FAILED = \033[0;31m

# Attributes (0 to 7)
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
REVERSED = \033[7m

# Foreground Colors (30 to 37)
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

GREY = \033[38;5;240m

# Highlight (Bright) Foreground Colors (90 to 97)
BRIGHT_BLACK = \033[0;90m
BRIGHT_RED = \033[0;91m
BRIGHT_GREEN = \033[0;92m
BRIGHT_YELLOW = \033[0;93m
BRIGHT_BLUE = \033[0;94m
BRIGHT_PURPLE = \033[0;95m
BRIGHT_CYAN = \033[0;96m
BRIGHT_WHITE = \033[0;97m

# Background Colors (40 to 47)
BG_BLACK = \033[0;40m
BG_RED = \033[0;41m
BG_GREEN = \033[0;42m
BG_YELLOW = \033[0;43m
BG_BLUE = \033[0;44m
BG_PURPLE = \033[0;45m
BG_CYAN = \033[0;46m
BG_WHITE = \033[0;47m

# Highlight (Bright) Background Colors (100 to 107)
BG_BRIGHT_BLACK = \033[0;100m
BG_BRIGHT_RED = \033[0;101m
BG_BRIGHT_GREEN = \033[0;102m
BG_BRIGHT_YELLOW = \033[0;103m
BG_BRIGHT_BLUE = \033[0;104m
BG_BRIGHT_PURPLE = \033[0;105m
BG_BRIGHT_CYAN = \033[0;106m
BG_BRIGHT_WHITE = \033[0;107m
```