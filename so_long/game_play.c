/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:26:50 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:26:51 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	destroy(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_colect)
		mlx_destroy_image(game->mlx, game->img_colect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

void	show_images(t_game *game)
{
	destroy(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall3.xpm",
			&game->img_width,
			&game->img_heigth);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor2.xpm",
			&game->img_width,
			&game->img_heigth);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./textures/player2.xpm",
			&game->img_width,
			&game->img_heigth);
	game->img_colect = mlx_xpm_file_to_image(game->mlx,
			"./textures/item2.xpm",
			&game->img_width,
			&game->img_heigth);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm",
			&game->img_width,
			&game->img_heigth);
}

static void	put_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			j * game->img_width, i * game->img_heigth);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			j * game->img_width, i * game->img_heigth);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			j * game->img_width, i * game->img_heigth);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_colect,
			j * game->img_width, i * game->img_heigth);
		game->items_count = 0;
		game->items_count = count_chars(game, 'C');
	}
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			j * game->img_width, i * game->img_heigth);
}

void	show_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	show_images(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_images(game, i, j);
			j++;
		}
		i++;
	}
}
