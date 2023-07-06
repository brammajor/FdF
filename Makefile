# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 15:19:57 by brmajor           #+#    #+#              #
#    Updated: 2023/07/06 14:40:36 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c read_map.c draw_line.c errors.c print_map.c draw_map.c close_window.c FdF.h 

CC = gcc -g

NAME = FdF

$(NAME):
	make -C	libft/
	$(CC) $(SRC) -L libft -l ft -L mlx_linux -l mlx_Linux -L /usr/lib -l Xext -l X11 -l m -l z -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

