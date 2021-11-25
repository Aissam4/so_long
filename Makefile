# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:27:23 by abarchil          #+#    #+#              #
#    Updated: 2021/11/24 12:35:32 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c check_map.c map_parsing.c so_long_utils.c draw_utils.c ft_draw.c ft_movment.c

NAME = so_long

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework  -c

CC = gcc
OBJ_FILE = $(SRC_FILE:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJ_FILe)
	ar rc $(NAME) $(OBJ_FILE)

$(OBJ_FILE) : $(SRC_FILE)
	$(CC) -c $(OBJ_FILE)
