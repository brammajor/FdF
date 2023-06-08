# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 15:19:57 by brmajor           #+#    #+#              #
#    Updated: 2023/06/08 14:19:26 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c read_map.c draw_line.c put_pixel.c FdF.h

CC = gcc

NAME = FdF

$(NAME): 
	$(CC) $(SRC) -L mlx_linux -l mlx_Linux -L /usr/lib -l Xext -l X11 -l m -l z -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

