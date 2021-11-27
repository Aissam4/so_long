/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:04:23 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/27 14:16:48 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_i;

void	ft_move_left(drawing_map *draw)
{
	if (draw->map[draw->posx][draw->posy - 1] == '1')
		return ;
	if (draw->map[draw->posx][draw->posy - 1] == 'X')
		exit(EXIT_SUCCESS);
	else if (draw->map[draw->posx][draw->posy - 1] == 'C')
	{
		draw->map[draw->posx][draw->posy - 1] = '0';
		draw->collectible_count--;
	}
	mlx_destroy_image(draw->mlx, draw->Player);
	printf("Movment : %d\n", g_i);
	g_i++;
	draw->posy -= 1;
}

void	ft_move_right(drawing_map *draw)
{
	if (draw->map[draw->posx][draw->posy + 1] == '1')
		return ;
	if (draw->map[draw->posx][draw->posy + 1] == 'X')
		exit(EXIT_SUCCESS);
	else if (draw->map[draw->posx][draw->posy + 1] == 'C')
	{
		draw->map[draw->posx][draw->posy + 1] = '0';
		draw->collectible_count--;
	}
	mlx_destroy_image(draw->mlx, draw->Player);
	printf("Movment : %d\n", g_i);
	g_i++;
	draw->posy += 1;
}

void	ft_move_down(drawing_map *draw)
{
	if (draw->map[draw->posx + 1][draw->posy] == '1')
		return ;
	if (draw->map[draw->posx + 1][draw->posy] == 'X')
		exit(EXIT_SUCCESS);
	else if (draw->map[draw->posx + 1][draw->posy] == 'C')
	{
		draw->map[draw->posx + 1][draw->posy] = '0';
		draw->collectible_count--;
	}
	mlx_destroy_image(draw->mlx, draw->Player);
	printf("Movment : %d\n", g_i);
	g_i++;
	draw->posx += 1;
}

void	ft_move_up(drawing_map *draw)
{
	if (draw->map[draw->posx - 1][draw->posy] == '1')
		return ;
	if (draw->map[draw->posx - 1][draw->posy] == 'X')
		exit(EXIT_SUCCESS);
	else if (draw->map[draw->posx - 1][draw->posy] == 'C')
	{
		draw->map[draw->posx - 1][draw->posy] = '0';
		draw->collectible_count--;
	}
	mlx_destroy_image(draw->mlx, draw->Player);
	printf("Movment : %d\n", g_i);
	g_i++;
	draw->posx -= 1;
}
