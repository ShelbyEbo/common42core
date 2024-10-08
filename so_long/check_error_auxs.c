/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_auxs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:09 by mebo              #+#    #+#             */
/*   Updated: 2024/08/20 15:24:09 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(char **map, t_point point)
{
	int	y;

	y = 0;
	while (y < point.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

static int	check_big_map(char **argv)
{
	t_game	game;
	char	*str;
	int		i;
	int		j;

	str = read_map(argv[1]);
	game.map = matriz(str);
	i = width(game.map);
	j = height(game.map);
	if (i > 1920 || j > 1080)
	{
		free_matrix(game.map);
		free(str);
		return (0);
	}
	free_matrix(game.map);
	free(str);
	return (1);
}

int	check_map_format(char **argv)
{
	t_game	game;
	char	*str;
	int		i;
	int		j;

	str = read_map(argv[1]);
	game.map = matriz(str);
	i = width(game.map);
	j = height(game.map);
	if (i == j || !check_big_map(argv))
	{
		free_matrix(game.map);
		free(str);
		ft_printf("Error\nToo big or square map!");
		return (0);
	}
	free_matrix(game.map);
	free(str);
	return (1);
}
