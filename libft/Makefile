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

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
      ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_itoa.c ft_memchr.c ft_memchrr.c \
      ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \

BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
            ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
            ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
    ar rcs $@ $^

bonus: $(OBJ) $(BONUS_OBJ)
    ar rcs $(NAME) $^

%.o: %.c
    gcc -Wall -Wextra -Werror -c $< -o $@

clean:
    rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
