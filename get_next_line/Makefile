# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 01:29:42 by hbani-at          #+#    #+#              #
#    Updated: 2025/09/20 01:34:59 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftgetnextline.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := get_next_line.c \
	   get_next_line_utils.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all

test:
	@touch test
	@echo "this is first line" >> test
	@echo "this is second line" >> test
	@echo "test created"

.PHONY: all clean fclean re
