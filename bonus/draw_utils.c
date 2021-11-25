/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:02:07 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/25 13:34:59 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(drawing_map *draw, char **map)
{
	draw->animate = 0;
	draw->game_over = 0;
	draw->map = map;
	draw->w = ft_strlen(map[0]) * PIXEL;
	draw->h = ft_strlen_2d(map) * PIXEL;
	draw->mlx = mlx_init();
	draw->mlx_window = mlx_new_window(draw->mlx, draw->w, \
			draw->h, "So_long");
	draw->floor = mlx_xpm_file_to_image(draw->mlx, "./img/lava.xpm", \
			&draw->w, &draw->h);
	draw->wall = mlx_xpm_file_to_image(draw->mlx, "./img/wall.xpm", \
			&draw->w, &draw->h);
	draw->collectible = mlx_xpm_file_to_image(draw->mlx, \
			"./img/pok_edit.xpm", &draw->w, &draw->h);
	draw->Player = mlx_xpm_file_to_image(draw->mlx, "./img/player.xpm", \
			&draw->w, &draw->h);
	draw->end_point = mlx_xpm_file_to_image(draw->mlx, "./img/door.xpm", \
			&draw->w, &draw->h);
	draw->enemy = mlx_xpm_file_to_image(draw->mlx, "./img/enemy_edit.xpm", \
			&draw->w, &draw->h);
	draw->game_over = mlx_xpm_file_to_image(draw->mlx, "./img/game_over_xpm", \
			&draw->w, &draw->h);
}

int	ft_loop(drawing_map *draw)
{
	ft_draw_floor(draw->map, draw->mlx, \
			draw->mlx_window, draw->floor);
	ft_draw_wall(draw->map, draw->mlx, \
			draw->mlx_window, draw->wall);
	ft_draw_collectible(draw->map, \
			draw->mlx, draw->mlx_window, draw->collectible);
	ft_draw_player(draw);
	ft_draw_enemy(draw->map, draw->mlx, \
			draw->mlx_window, draw->enemy);
	sprite(draw);
	ft_draw_end_point(draw->map, draw->mlx, \
			draw->mlx_window, draw->end_point);
	return (0);
}

// void	mlx_sprite(drawing_map *draw)
// {
// 	draw->sprite_1 = mlx_xpm_file_to_image(draw->mlx, \
// 			"./img/sprite1.xpm", &draw->w, &draw->h);
// 	draw->sprite_2 = mlx_xpm_file_to_image(draw->mlx, \
// 			"./img/sprite-2.xpm", &draw->w, &draw->h);
// 	draw->sprite_3 = mlx_xpm_file_to_image(draw->mlx, \
// 			"./img/sprite-3.xpm", &draw->w, &draw->h);
// }

// void	sprite(drawing_map *draw)
// {
// 	int	j;

// 	j = draw->animate % 3;
// 	mlx_sprite(draw);
// 	if (j == 0)
// 	{
// 		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
// 				draw->sprite_1, PIXEL * 1, PIXEL * 1);
// 		mlx_destroy_image(draw->mlx, draw->sprite_1);
// 		draw->animate++;
// 	}
// 	if (j == 1)
// 	{
// 		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
// 				draw->sprite_2, PIXEL * 1, PIXEL * 1);
// 		mlx_destroy_image(draw->mlx, draw->sprite_2);
// 		draw->animate++;
// 	}
// 	if (j == 2)
// 	{
// 		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
// 				draw->sprite_3, PIXEL * 1, PIXEL * 1);
// 		mlx_destroy_image(draw->mlx, draw->sprite_3);
// 		draw->animate++;
// 	}
// }

// void	find_player(drawing_map *draw)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (draw->map[j])
// 	{
// 		i = 0;
// 		while (draw->map[j][i])
// 		{
// 			if (draw->map[j][i] == 'P')
// 			{
// 				draw->posx = j;
// 				draw->posy = i;
// 				return ;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	find_enemy(drawing_map *draw)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (draw->map[j])
// 	{
// 		i = 0;
// 		while (draw->map[j][i])
// 		{
// 			if (draw->map[j][i] == 'X')
// 			{
// 				draw->enemyx = j;
// 				draw->enemyy = i;
// 				return ;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

int	key_hook(int keycode, drawing_map *draw)
{
	if (keycode == 1)
		ft_move_down(draw);
	else if (keycode == 13)
		ft_move_up(draw);
	else if (keycode == 2)
		ft_move_right(draw);
	else if (keycode == 0)
		ft_move_left(draw);
	else if (keycode == 53)
		exit (EXIT_SUCCESS);
	if (draw->map[draw->posx][draw->posy] == 'E' && \
			draw->collectible_count == 0)
		exit (EXIT_SUCCESS);
	draw->Player = mlx_xpm_file_to_image(draw->mlx, \
			"./img/player.xpm", &draw->w, &draw->h);
	mlx_put_image_to_window(draw->mlx, draw->mlx_window, draw->Player, \
			PIXEL * draw->posy, PIXEL * draw->posx);
	return (0);
}

int	ft_exit(void)
{
	exit (EXIT_SUCCESS);
	return (0);
}

void	ft_start_game(char **map)
{
	drawing_map	draw;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_init(&draw, map);
	find_player(&draw);
	find_collectible(&draw);
	find_enemy(&draw);
	sprite(&draw);
	mlx_key_hook(draw.mlx_window, key_hook, &draw);
	mlx_hook(draw.mlx_window, 17, 2, &ft_exit, draw.mlx);
	mlx_loop_hook(draw.mlx, ft_loop, &draw);
	mlx_loop(draw.mlx);
}
