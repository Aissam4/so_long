/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:27:33 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/26 20:09:22 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;	
	int		j;

	i = 0;
	j = 0;
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
	ft_loop(map);
	return (0);
}
