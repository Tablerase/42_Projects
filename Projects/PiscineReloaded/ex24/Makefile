# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:11:25 by rcutte            #+#    #+#              #
#    Updated: 2023/11/02 15:53:53 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wextra -Wall -Werror 
SRC_PATH = srcs/
INC = includes/
SRC = $(SRC_PATH)ft_putchar.c\
      $(SRC_PATH)ft_putstr.c\
      $(SRC_PATH)ft_strcmp.c\
      $(SRC_PATH)ft_strlen.c\
      $(SRC_PATH)ft_swap.c
OBJ = $(SRC:.c=.o)
AR = ar cs
#AR =  ar -crsv for details during launch

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) -r $?

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
