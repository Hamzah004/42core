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

CC = cc
CFLAGS := -Wall -Werror -Wextra
NAME = push_swap
SRC := 	main.c \
	push_swap.c \
       	utils.c
OBJS := $(SRC:.c=.o)
LIBFT_DIR = ./libft
PRINTF_DIR = ./printf
LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(PRINTF_A):
	@make -C $(PRINTF_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
