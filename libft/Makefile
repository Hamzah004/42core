# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 18:17:03 by hbani-at          #+#    #+#              #
#    Updated: 2025/08/28 19:53:35 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
COM_STRING   = "Compiling"

NAME := libft.a
CC := cc
CFLAGS := -g3 -Wall -Werror -Wextra
SRC := ft_atoi.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_strdup.c \
       ft_strchr.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_strtrim.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_split.c

BONUS_SRC := ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \

OBJ := $(SRC:.c=.o)
BONUS_OBJ := $(BONUS_SRC:.c=.o)
BONUS_MARKER := .bonus_marker

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(OK_COLOR)$(OK_STRING) libft archive cerated\n$(NO_COLOR)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $<\n$(NO_COLOR)"

bonus: $(BONUS_MARKER)

$(BONUS_MARKER): $(BONUS_OBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@touch $(BONUS_MARKER)
	@printf "$(OK_COLOR)$(OK_STRING) libft archive cerated with bonus part\n$(NO_COLOR)"

clean:
	@rm -f $(OBJ) $(BONUS_OBJ) $(BONUS_MARKER)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Libft Object files cleaned\n$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Libft archive cleaned\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean bonus re
