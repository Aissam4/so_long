/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:26:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/27 13:54:39 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
