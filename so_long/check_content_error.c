/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:10:58 by mebo              #+#    #+#             */
/*   Updated: 2024/08/15 13:10:59 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	freers(t_game game, char *str)
{
	free_matrix(game.map);
	free(str);
}

int	check_content_error(char **argv)
{
	t_game	game;
	char	*str;
	int		i;
	int		j;

	str = read_map(argv[1]);
	game.map = matriz(str);
	i = 0;
	while (++i < (height(game.map) / 50))
	{
		j = 0;
		while (++j < (width(game.map) / 50))
		{
			if (game.map[i][j] != '0' && game.map[i][j] != 'C'
			&& game.map[i][j] != '1' && game.map[i][j] != 'P'
		&& game.map[i][j] != 'E')
			{
				freers(game, str);
				ft_printf("Error\nInvalid chars");
				return (0);
			}
		}
	}
	freers(game, str);
	return (1);
}

static int	check_number_of(char **argv)
{
	t_game	game;
	char	*str;

	str = read_map(argv[1]);
	game.map = matriz(str);
	if (count_chars(&game, 'E') != 1 || count_chars(&game, 'P') != 1
		|| count_chars(&game, 'C') < 1)
	{
		freers(game, str);
		ft_printf("Error\nInvalid number of Players/Exits/Items");
		return (0);
	}
	freers(game, str);
	return (1);
}

int	check_map(char **argv)
{
	if (check_number_of(argv) && check_map_format(argv)
		&& check_error(argv) && check_content_error(argv)
		&& check_double_new_line(argv))
		return (1);
	else
		return (0);
}
