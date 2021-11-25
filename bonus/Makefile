# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:27:23 by abarchil          #+#    #+#              #
#    Updated: 2021/11/25 13:50:08 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c check_map.c map_parsing.c so_long_utils.c draw_utils.c ft_draw.c ft_movment.c ft_sprite.c

NAME = so_long

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework  -c

CC = gcc
OBJ_FILE = $(SRC_FILE:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJ_FILe)


$(OBJ_FILE) : $(SRC_FILE)
	$(CC) -c $(OBJ_FILE)
