# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:18:09 by brmajor           #+#    #+#              #
#    Updated: 2023/05/26 13:52:30 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi.c \
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
        ft_putchar_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_putstr_fd.c \
        ft_split.c \
        ft_strchr.c \
        ft_strdup.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strmapi.c \
        ft_strncmp.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_strtrim.c \
        ft_substr.c \
        ft_tolower.c \
        ft_toupper.c ft_printf.c putcharf.c putdecf.c puthexf.c putnbrf.c putptrf.c putstrf.c utils.c\


BONUS_SRC =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
	    	ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		$(SRC)

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
OBJ_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ))
BONUS_OBJ_PREFIXED = $(addprefix $(OBJ_DIR), $(BONUS_OBJ))

$(OBJ_DIR)%.o: %.c libft.h
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PREFIXED)
	@ar r $(NAME) $(OBJ_PREFIXED)
	@echo $(NAME) created
	@echo Compilation completed

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f *.o
	@echo Object files removed

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) removed

bonus:	$(BONUS_OBJ_PREFIXED) $(NAME)
	@ar r $(NAME) $(BONUS_OBJ_PREFIXED)
	@echo $(NAME) updated with bonus functions

re: fclean all

.PHONY: all clean fclean re
