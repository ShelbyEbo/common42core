/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:25:03 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:25:04 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_pos_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_x = i;
				game->pos_y = j;
			}
			j++;
		}
		i++;
	}
}

static void	check_exit(int key, t_game *game)
{
	int	x;
	int	y;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	if ((key == 'W' || key == 'w') && game->map[x - 1][y] == 'E'
		&& !game->items_count)
		keypress(81, game);
	if ((key == 'S' || key == 's') && game->map[x + 1][y] == 'E'
		&& !game->items_count)
		keypress(81, game);
	if ((key == 'A' || key == 'a') && game->map[x][y - 1] == 'E'
		&& !game->items_count)
		keypress(81, game);
	if ((key == 'D' || key == 'd') && game->map[x][y + 1] == 'E'
		&& !game->items_count)
		keypress(81, game);
}

int	keypress(int key, t_game *game)
{
	if (key == 65307 || key == 81 || key == 113)
	{
		if (game->items_count == 0)
			ft_printf("\033[32mCongratulations, YOU WON!\033[0m");
		ft_destroy(game);
		exit(ft_printf("Window closed\n"));
	}
	if (game->items_count == 0)
		check_exit(key, game);
	game->items_count -= check_moves_up(key, game);
	game->items_count -= check_moves_down(key, game);
	game->items_count -= check_moves_right(key, game);
	game->items_count -= check_moves_left(key, game);
	show_map(game);
	return (0);
}
