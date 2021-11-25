/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:18:09 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/25 11:57:11 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memzero(size_t size)
{
	char	*dest;
	int		count;

	count = 0;
	dest = (char *)malloc(sizeof(char) * size);
	if (dest)
	{
		while (size != 0)
		{
			dest[count++] = 0;
			size--;
		}
		return (dest);
	}
	else
		return (NULL);
}

static int	word_length(char const *s, char c)
{
	int	len;

	len = 0;
	if (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	while (*s != 0)
	{
		if (*s != c)
			len++;
		s++;
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	j;
	char			**splited;

	if (s == NULL)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * word_length(s, c));
	if (!splited)
		return (NULL);
	j = 0;
	while (*s != 0)
	{
		count = 0;
		while (s[count] != c && s[count] != 0)
			count++;
		if (count)
		{
			splited[j++] = ft_memcpy(ft_memzero(count + 1), s, count);
			s = &s[count];
		}
		else
			s++;
	}
	splited[j] = NULL;
	return (splited);
}

char	*read_file(char *file_name)
{
	char	*line;
	char	*map;
	char	*buffer;
	int		fd;
	int		byte;

	fd = open(file_name, O_RDONLY);
	map = ft_strdup("");
	buffer = ft_strdup("");
	while (buffer)
	{
		buffer = get_next_line(fd);
		map = ft_strjoin(map, buffer);
	}
	free(buffer);
	close (fd);
	return (map);
}

char	**get_map(char *file_name)
{
	int		len;
	char	*tab;
	char	**map;

	tab = read_file(file_name);
	map = ft_split(tab, '\n');
	free(tab);
	return (map);
}
