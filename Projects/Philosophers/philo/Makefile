# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:51:05 by rcutte            #+#    #+#              #
#    Updated: 2024/03/07 12:51:48 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################### Program ######################

NAME = philo

all: $(NAME)

####################### FLAGS #######################

CC = cc
CFLAGS = -Wextra -Wall -Werror -g3
THREADS = -pthread

ADD_FLAGS = $(THREADS)

###################### Mandatory ########################

# header path
INCLUDE = ./include
# source path
SRC_PATH = ./src/

# files
SRC = main.c \
		arguments.c \
		parser.c \
		init.c \
		philosophers.c \
		philo_life.c \
		philo_eat.c \
		philo_death.c \
		watcher.c \
		time.c \
		str_utils.c \
		mem_manager.c \
		debug.c \
		debug_print.c \

# objet libft
OBJ = $(addprefix $(SRC_PATH)/,$(SRC:.c=.o))

##################### Building ######################

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(ADD_FLAGS) -o $(NAME)
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
	$(CC) -c $(CFLAGS) -I$(INCLUDE) -o $@ $<

###################### Commandes ######################

clean: clean_msg
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: re_msg fclean all

####################### Tests ########################

ARGS = 50 410 200 200 2

exec: all exec_msg
	@./$(NAME) $(ARGS)

time: all time_msg
	@start=$$(date +%s%N); \
    ./$(NAME) $(ARGS) ;\
    end=$$(date +%s%N); \
    elapsed=$$((($$end - $$start)/1000000)); \
    echo "\t\tElapsed time: $$elapsed ms"

###################### Valgrind/Debug ######################

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all -s \
 --trace-children=yes --track-origins=yes \
	./$(NAME) $(ARGS)

valgrind_fd: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
 --trace-children=yes --track-fds=yes \
	./$(NAME) $(ARGS)

valgrind_thread: all
	@valgrind --tool=helgrind -s \
	./$(NAME) $(ARGS)

lldb: all
	@lldb ./$(NAME) $(ARGS)

gdb: all
	@gdb --args $(NAME) $(ARGS)

################### Special Target ###################

.PHONY: all clean fclean re \
	exec \
	valgrind valgrind_fd valgrind_thread \
	lldb

.SILENT: $(NAME) $(OBJ)

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

time_msg:
	@echo "$(EXEC)\
	╭──────────────────────────────────────────────────╮\n\
	│                 🕰️  Time Program  🕰️               │\n\
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