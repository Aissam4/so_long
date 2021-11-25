/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:45:08 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/25 17:53:38 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

size_t     ft_strlen_2d(char **map)
{
    size_t  count;
    size_t  j;

    count = 0;
    j = 0;
    while (map[j])
        j++;
    return (j);
}
void    find_collectible(drawing_map *draw)
{
    int i;
    int j;

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
/*
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str2;
	unsigned char	*str1;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/
