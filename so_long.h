/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:15:01 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/24 18:00:44 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# define PIXEL 30
typedef struct drawing_win_floor_wall // norme name
{
    int     posx;
    int     posy;
    int     collectible_count;
    char    **map;
    void    *mlx;
    void    *mlx_window;
    void    *floor;
    void    *wall;
    void    *collectible;
    void    *Player;
    void    *end_point;
    void    *sprite_1;
    void    *sprite_2;
    void    *sprite_3;
    int     w;
    int     h;
    int     animate;
}   drawing_map;
// Drawing
void    ft_draw_floor(char **map, char *mlx, char *mlx_window, char *floor);
void    ft_draw_wall(char **map, char *mlx, char *mlx_window, char *wall);
void    ft_draw_collectible(char **map, char *mlx, char *mlx_window, char *collectible);
void    ft_draw_player(drawing_map *draw);
void    ft_draw_end_point(char **map, char *mlx, char *mlx_window, char *end_point);
//  Find a position
void    find_player(drawing_map *draw);
void    find_collectible(drawing_map *draw);
//  len calculate
size_t	ft_strlen(const char *s);
size_t  ft_strlen_2d(char **map);
// player movement
void    ft_move_left(drawing_map *draw);
void    ft_move_right(drawing_map *draw);
void    ft_move_down(drawing_map *draw);
void    ft_move_up(drawing_map *draw);
// utils from libft
char	*ft_strchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
//check for errors
int check_walls(char **map, int i, int j);
int     check_map_name(char *map_name);
int     check_map(char **map);
// it will continue to call your hook registered in mlx_loop_hook to render new frames,
//which you obviously have to pass to the window yourself.
void     ft_loop(char **map);
// Puts the images to the given window instance at location (x,y)
int     ft_draw(drawing_map *draw);
// get and parcing the map 
char    **get_map(char *file_name);
// reading from the file that contine the map
char    *read_file(char *file_name);
// sprite
void	sprite(drawing_map *draw);
#endif