# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 10:56:41 by hbani-at          #+#    #+#              #
#    Updated: 2025/08/06 21:03:50 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
SRC	= ft_isalpha.c ft_isdigit.c
OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar asc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
