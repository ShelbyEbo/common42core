/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_auxs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:55:50 by mebo              #+#    #+#             */
/*   Updated: 2024/08/12 13:55:51 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	g_moves;

int	count_chars(t_game *game, char c)
{
	int	i;
	int	j;
	int	items;

	items = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				items++;
			j++;
		}
		i++;
	}
	return (items);
}

int	check_moves_up(int key, t_game *game)
{
	int	j;
	int	x;
	int	y;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'W' || key == 'w')
	{
		if (game->map[x - 1][y] != '1' && game->map[x - 1][y] != 'E')
		{
			if (game->map[x - 1][y] == 'C')
				j = 1;
			game->map[x][y] = '0';
			game->map[x - 1][y] = 'P';
			ft_printf("%d\n", g_moves++);
		}
	}
	return (j);
}

int	check_moves_down(int key, t_game *game)
{
	int	j;
	int	x;
	int	y;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'S' || key == 's')
	{
		if (game->map[x + 1][y] != '1' && game->map[x + 1][y] != 'E')
		{
			if (game->map[x + 1][y] == 'C')
				j = 1;
			game->map[x][y] = '0';
			game->map[x + 1][y] = 'P';
			ft_printf("%d\n", g_moves++);
		}
	}
	return (j);
}

int	check_moves_left(int key, t_game *game)
{
	int	j;
	int	x;
	int	y;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'A' || key == 'a')
	{
		if (game->map[x][y - 1] != '1' && game->map[x][y - 1] != 'E')
		{
			if (game->map[x][y - 1] == 'C')
				j = 1;
			game->map[x][y] = '0';
			game->map[x][y - 1] = 'P';
			ft_printf("%d\n", g_moves++);
		}
	}
	return (j);
}

int	check_moves_right(int key, t_game *game)
{
	int	j;
	int	x;
	int	y;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'D' || key == 'd')
	{
		if (game->map[x][y + 1] != '1' && game->map[x][y + 1] != 'E')
		{
			if (game->map[x][y + 1] == 'C')
				j = 1;
			game->map[x][y] = '0';
			game->map[x][y + 1] = 'P';
			ft_printf("%d\n", g_moves++);
		}
	}
	return (j);
}
