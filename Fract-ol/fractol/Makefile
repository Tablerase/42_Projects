# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:51:05 by rcutte            #+#    #+#              #
#    Updated: 2023/12/18 00:51:37 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################### Program ######################

NAME = fractol
OS = $(shell uname)

all: $(NAME)

####################### FLAGS #######################

CC = cc
CFLAGS = -Wextra -Wall -Werror -g
MATH = -lm

####################### MLX #########################

MLX = ./mlx

ifeq ($(OS), Linux)
	MLX_FLAGS = -L$(MLX) -lmlx -lXext -lX11
else
	MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
endif

mlx_setup:
	@if [ ! -d $(MLX) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx \
			2> /dev/null ; \
	fi
	@if [ ! -f $(MLX)/libmlx.a ]; then \
		make -sC $(MLX) > /dev/null 2>&1 ; \
		echo "$(GREEN)MiniLibX Installed$(RESET)"; \
	fi
	@if [ ! -f $(MLX)/libmlx.a ]; then \
		rm -rf $(MLX); \
		echo "$(RED)MiniLibX Installation Failed$(RESET)"; \
	fi

mlx_clean:
	@if [ -f $(MLX)/Makefile.gen ]; then \
		make -sC $(MLX) clean > /dev/null 2>&1 ; \
		echo "$(ORANGE)MiniLibX Library Cleaned$(RESET)"; \
	fi

mlx_delete:
	@if [ -d $(MLX) ]; then \
		rm -rf $(MLX); \
		echo "$(RED)MiniLibX Deleted$(RESET)"; \
	fi

###################### Libft ########################

LIB_PATH = ./libft
LIB_Includes = ./libft/Includes
LIBFT = $(LIB_PATH)/libft.a

lib_setup:
	@if [ ! -f $(LIB_PATH)/libft.a ]; then \
		make -sC $(LIB_PATH) ; \
		echo "$(GREEN)Libft Library Created$(RESET)"; \
	fi
	
lib_clean:
	@if [ -f $(LIB_PATH)/Libft/ft_tolower.o ]; then \
		make -sC $(LIB_PATH) clean; \
		echo "$(ORANGE)Libft Objects Cleaned$(RESET)"; \
	fi

lib_fclean:
	@make -sC $(LIB_PATH) fclean
	@echo "$(ORANGE)Libft Library Cleaned$(RESET)"

###################### Files ########################

# header path
INCLUDES = ./Includes
# source path
SRC_PATH = ./Sources/mandatory

# files
SRC = fractol.c\
	fractal.c	julia.c	mandelbrot.c\
	get_color.c\
	key_hook.c	mouse_hook.c\
	mlx_manager.c	xpm_image.c\
	struct_manager.c\
	messages.c\
	atof.c\

# objet libft
OBJ = $(addprefix $(SRC_PATH)/,$(SRC:.c=.o))

###################### Bonus ########################

SRC_BONUS_PATH = ./Sources/bonus
SRC_BONUS = fractol_bonus.c\
	fractal_bonus.c	julia_bonus.c	mandelbrot_bonus.c burningship_bonus.c\
	get_color_bonus.c\
	key_hook_bonus.c	mouse_hook_bonus.c\
	mlx_manager_bonus.c	xpm_image_bonus.c\
	struct_manager_bonus.c\
	messages_bonus.c\
	atof_bonus.c\

OBJ_BONUS = $(addprefix $(SRC_BONUS_PATH)/,$(SRC_BONUS:.c=.o))

bonus: lib_setup mlx_setup $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) $(MATH)
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)Fractol bonus Compiled$(RESET)"; \
	fi
	@if [ ! -f $(NAME) ]; then \
		echo "$(RED)Fractol bonus Compilation Failed$(RESET)"; \
	fi

rebonus: re_msg mlx_delete fclean bonus

##################### Commands ######################

$(NAME): lib_setup mlx_setup $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME) $(MATH)
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)Fractol Compiled$(RESET)"; \
	fi
	@if [ ! -f $(NAME) ]; then \
		echo "$(RED)Fractol Compilation Failed$(RESET)"; \
	fi

%.o : %.c
	$(CC) -c $(CFLAGS) -I$(INCLUDES) -I$(LIB_Includes) -I$(MLX) $< -o $@

clean: lib_clean
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "$(ORANGE)Fractol Objects Cleaned$(RESET)"
	
fclean: clean mlx_delete lib_fclean
	@rm -f $(NAME)
	@rm -f fractal.xpm

exec: clean exec_msg all
	@./$(NAME) julia
	
re: re_msg mlx_delete fclean all

re_program: re_program_msg clean all

###################### Valgrind ######################

valgrind: clean all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) mandelbrot

################### Special Target ###################

.PHONY: all clean fclean re re_program bonus rebonus exec valgrind

.SILENT: $(NAME) $(OBJ) $(OBJ_BONUS)

###################### Messages ######################
re_msg:
	@echo "$(PURPLE) ######### Recreation of Fractol and Libraries \
		######### $(RESET)"

re_program_msg:
	@echo "$(PURPLE) ######### Recreation of Fractol ######### $(RESET)"

exec_msg:
	@echo "$(PURPLE) ########## Execution of Fractol ######### $(RESET)"

###################### Colors #######################

GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
PURPLE = \033[0;35m

RESET = \033[0m
