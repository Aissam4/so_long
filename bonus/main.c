/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:27:33 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/25 11:25:23 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (argc == 1 || argc >= 3)
	{
		printf("\033[0;31m");
		printf("No Such File or Directory");
		return (0);
	}
	map = get_map(argv[1]);
	if (check_map_name(argv[1]) == 0 || check_map(map) == 0)
	{
		printf("\033[0;33m");
		printf("NO valid Map");
		return (0);
	}
	ft_start_game(map);
	return (0);
}
