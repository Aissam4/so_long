# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:27:23 by abarchil          #+#    #+#              #
#    Updated: 2021/11/27 03:12:56 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c check_map.c map_parsing.c so_long_utils.c draw_utils.c   gnl/get_next_line.c gnl/get_next_line_utils.c  ft_draw.c ft_movment.c ft_sprite.c SRC/*.c
NAME = so_long
FLAG = gcc -lmlx -framework OpenGL -framework AppKit
CC = cc
OBJ = $(SRC_FILE;.c=.o)

all : $(NAME)

%.o : %.c
	cc -c @^ -o $@

$(NAME) :	$(OBJ)
	$(FLAG) $(SRC_FILE) -o $(NAME)
clean :
	rm $(NAME)


re : fclean all

.PHONY : all clean fclean re
