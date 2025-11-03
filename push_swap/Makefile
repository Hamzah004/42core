# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Gemini <gemini@google.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 10:00:00 by Gemini            #+#    #+#              #
#    Updated: 2025/10/28 10:00:00 by Gemini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := push_swap.c \
       utils.c
LIBFT = libft.a
LIBPRINTF = libprintf.a
LIBFT_PATH = ./libft/
LIBPRINTF_PATH = ./printf/

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBPRINTF) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -L $(LIBFT_PATH) -l libft
	$(MAKE) ./libft/clean

$(LIBPRINTF):
	$(MAKE) $(LIBPRINTF_PATH)
	$(MAKE) ./printf/clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
