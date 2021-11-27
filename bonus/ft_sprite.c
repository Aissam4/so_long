/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:34:29 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/26 22:22:10 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_sprite(drawing_map *draw)
{
	draw->sprite_1 = mlx_xpm_file_to_image(draw->mlx, \
			"./img/sprite1.xpm", &draw->w, &draw->h);
	draw->sprite_2 = mlx_xpm_file_to_image(draw->mlx, \
			"./img/sprite-2.xpm", &draw->w, &draw->h);
	draw->sprite_3 = mlx_xpm_file_to_image(draw->mlx, \
			"./img/sprite-3.xpm", &draw->w, &draw->h);
}

void	sprite(drawing_map *draw)
{
	int	j;

	j = draw->animate % 3;
	mlx_sprite(draw);
	if (j == 0)
	{
		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
				draw->sprite_1, PIXEL * 1, PIXEL * 1);
		mlx_destroy_image(draw->mlx, draw->sprite_1);
		draw->animate++;
	}
	if (j == 1)
	{
		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
				draw->sprite_2, PIXEL * 1, PIXEL * 1);
		mlx_destroy_image(draw->mlx, draw->sprite_2);
		draw->animate++;
	}
	if (j == 2)
	{
		mlx_put_image_to_window(draw->mlx, draw->mlx_window, \
				draw->sprite_3, PIXEL * 1, PIXEL * 1);
		mlx_destroy_image(draw->mlx, draw->sprite_3);
		draw->animate++;
	}
}

void	find_player(drawing_map *draw)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (draw->map[j])
	{
		i = 0;
		while (draw->map[j][i])
		{
			if (draw->map[j][i] == 'P')
			{
				draw->posx = j;
				draw->posy = i;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	find_enemy(drawing_map *draw)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (draw->map[j])
	{
		i = 0;
		while (draw->map[j][i])
		{
			if (draw->map[j][i] == 'X')
			{
				draw->enemyx = j;
				draw->enemyy = i;
				return ;
			}
			i++;
		}
		j++;
	}
}
