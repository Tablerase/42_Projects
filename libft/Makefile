# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:42:12 by rcutte            #+#    #+#              #
#    Updated: 2023/11/14 22:48:17 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -I. 
SRC = ft_isascii.c  ft_memmove.c  ft_strlcpy.c  ft_substr.c\
	ft_atoi.c     ft_isdigit.c  ft_memset.c   ft_strlen.c   ft_tolower.c\
	ft_bzero.c    ft_isprint.c  ft_strchr.c   ft_strncmp.c  ft_toupper.c\
	ft_calloc.c   ft_memchr.c   ft_strdup.c   ft_strnstr.c\
	ft_isalnum.c  ft_memcmp.c   ft_strjoin.c  ft_strrchr.c\
	ft_isalpha.c  ft_memcpy.c   ft_strlcat.c  ft_strtrim.c\
	ft_split.c	ft_itoa.c	ft_strmapi.c	ft_striteri.c\
	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
	
OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c\

OBJ_BONUS = $(SRC_BONUS:.c=.o)

AR = ar -rcsv
AR_BONUS = ar -rsv

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $?

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(OBJ_BONUS)
	$(AR_BONUS) $(NAME) $(OBJ_BONUS)

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
