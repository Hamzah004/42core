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

COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
COM_STRING   = "Compiling"

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
NAME = push_swap
SRC = 	main.c \
				push_swap.c \
       	input_validation.c \
				stack.c \
				mini_sort.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				swap.c \
				radix_sort.c \
				insertion_sort.c
				

OBJS = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@printf "$(OK_COLOR)$(OK_STRING) final push swap executable successfully created\n$(NO_COLOR)"

$(LIBFT_A):
	@make --no-print-directory -C $(LIBFT_DIR) bonus
	@printf "$(OK_COLOR)$(OK_STRING) libft archive cerated\n$(NO_COLOR)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $<\n$(NO_COLOR)"

clean:
	@rm -f $(OBJS)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Push swap Object files cleaned\n$(NO_COLOR)";
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Push swap executable cleaned\n$(NO_COLOR)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
