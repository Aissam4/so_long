/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:33:39 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/24 12:27:26 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int check_map_name(char *map_name)
{
    int len;
    char    *ext;
    ext = ft_strchr(map_name, '.');
    if (ext == NULL)
        return (0);
    if (ft_strncmp(ext, ".ber", 4) == 0)
        return (1);
    return (0);
}

int check_map(char **map)
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    if (!map)
        return(0);
    while(map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j++;
    }
    i++;
    if (check_walls(map,i,j) == 0)
        return (0);
    i = ft_strlen_2d(map) - 1;
    j = 0;
    while(map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j++;
    }
    return (1);
}
int check_walls(char **map, int i, int j)
{
    j = 0;
    while (map[i])
    {
        if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
            return (0);
        else if(map[i][0] != '1')
                return (0);
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '1' && map[i][j] != '0')
                return (0);
            j++;
        }
        if (map[i][j - 1] != '1')
            return(0);
        i++;
    }
    return (1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	count = 0;
	if (!src && !dest)
		return (NULL);
	while (count < n)
	{
		dest1[count] = src1[count];
		count++;
	}
	return (dest1);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*src;
	int		count;
	int		s_len;

	count = 0;
	src = (char *)s;
	s_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(const char) * s_len + 1);
	if (!dest)
		return (NULL);
	while (count < s_len)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}