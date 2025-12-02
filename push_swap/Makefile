# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 21:30:40 by hbani-at          #+#    #+#              #
#    Updated: 2025/11/07 22:07:09 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
NAME = push_swap
SRC = 	main.c \
				push_swap.c \
       	input_parsing.c \
				stack.c \
				mini_sort.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				swap.c
				

OBJS = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR) bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
