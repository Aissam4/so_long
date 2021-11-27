/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:45:08 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/27 03:22:11 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_2d(char **map)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = 0;
	while (map[j])
		j++;
	return (j);
}

void	find_collectible(drawing_map *draw)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	draw->collectible_count = 0;
	while (draw->map[j])
	{
		i = 0;
		while (draw->map[j][i])
		{
			if (draw->map[j][i] == 'C')
				draw->collectible_count++;
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
