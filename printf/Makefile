# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 18:17:03 by hbani-at          #+#    #+#              #
#    Updated: 2025/09/02 16:54:07 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := ft_printf.c \
       ft_putchar.c \
       ft_putstr.c \
       ft_putnbr.c \
       ft_putnbr_unsigned.c \
       ft_hexa.c \
       ft_putpointer.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
