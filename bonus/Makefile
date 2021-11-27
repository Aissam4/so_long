# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:27:23 by abarchil          #+#    #+#              #
#    Updated: 2021/11/27 14:15:52 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c check_map.c map_parsing.c so_long_utils.c draw_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_draw.c ft_movment.c ft_sprite.c ft_strncmp.c ft_strchr.c
NAME = so_long
FLAG = gcc -lmlx -framework OpenGL -framework AppKit
CC = cc
OBJ = $(SRC_FILE:.c=.o)

BLUE=\033[0;34m
GREEN=\033[0;32m
ORANG=\033[0;33m

all : $(NAME)

%.o : %.c
	@cc -c $< -o $@
	@echo "$(GREEN)compiling  $@ ..."
$(NAME) : $(OBJ)
	@echo "$(BLUE) linking Object files..."
	@$(FLAG) $(OBJ) -o $(NAME)
clean :
	@echo "$(ORANG)removing ... $(OBJ)"
	@rm $(OBJ)
fclean : clean
	@echo "remove $(NAME)"
	@rm $(NAME)
re : fclean all
.PHONY : clean fclean all re
