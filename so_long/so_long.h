/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:25:30 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:25:31 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_game
{
	int		pos_x;
	int		pos_y;
	int		player;
	int		img_heigth;
	int		img_width;
	int		items_count;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	char	**map;
	char	**map_copy;
	char	**map_exit;
	char	*path_wall;
	char	*path_floor;
	char	*path_player;
	char	*path_colect;
	char	*path_exit;

}t_game;

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

//utils
int		width(char **matriz);
int		height(char **matriz);
int		ft_linelen(char *str);
char	**matriz(char *str);

//mapa
char	*read_map(char *src);
void	show_map(t_game *game);
void	show_images(t_game *game);

//keyboard events
int		keypress(int key, t_game *game);

//liberacao
int		ft_destroy(t_game *game);
void	free_matrix(char **mtr);
void	freers(t_game game, char *str);
void	free_map(char **map, t_point point);

//erros
int		check_error(char **argv);
int		check_map_format(char **argv);
int		check_content_error(char **argv);
int		check_line(char *str);
int		check_wall(char **argv);
int		check_map(char **argv);
int		check_double_new_line(char **argv);
int		check_collectible_acessible(t_game *game);
int		check_exit_acessible(t_game *game);
//int		check_player_acessible(t_game *game);
int		check_is_not_stuck(t_game *game);
void	player_flood_fill(char **map_copy, t_point point, int *acess);
void	player_flood_fill_exit(char **map_exit, t_point point, int *acess);
void	flood_fill(char **map, int x, int y, int *reachable);
void	flood_fill_exit(char **map, int x, int y, int *reachable);

//movimentos

int		count_chars(t_game *game, char c);
int		check_moves_up(int key, t_game *game);
int		check_moves_down(int key, t_game *game);
int		check_moves_right(int key, t_game *game);
int		check_moves_left(int key, t_game *game);
void	check_pos_player(t_game *game);
#endif
