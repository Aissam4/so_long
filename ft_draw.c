/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:29:49 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/26 20:13:32 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_floor(char **map, char *mlx, char *mlx_window, char *floor)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(mlx, mlx_window, \
					floor, PIXEL * i, PIXEL * j);
			i++;
		}
		j++;
	}
}

void	ft_draw_wall(char **map, char *mlx, char *mlx_window, char *wall)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx, mlx_window, wall, \
						PIXEL * i, PIXEL * j);
			i++;
		}
		j++;
	}
}

void	ft_draw_collectible(char **map, char *mlx, \
		char *mlx_window, char *collectible)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, \
						collectible, PIXEL * i, PIXEL * j);
			i++;
		}
		j++;
	}
}

void	ft_draw_player(drawing_map *draw)
{
	mlx_put_image_to_window(draw->mlx, draw->mlx_window, draw->Player, \
			PIXEL * draw->posy, PIXEL * draw->posx);
	return ;
}

void	ft_draw_end_point(char **map, char *mlx, \
		char *mlx_window, char *end_point)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				mlx_put_image_to_window(mlx, mlx_window, \
						end_point, PIXEL * i, PIXEL * j);
				return ;
			}
			i++;
		}
		j++;
	}
}
