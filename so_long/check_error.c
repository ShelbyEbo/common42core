/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:26:11 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:26:12 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.'
		&&argv[1][i - 5] == '/')
	{
		ft_printf("Error\nInvalid map format!");
		exit(EXIT_SUCCESS);
	}
	else if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.')
		return (1);
	else
	{
		ft_printf("Error\nInvalid map format!");
		exit(EXIT_SUCCESS);
	}
}

static int	previous_check_line(t_game game, int j)
{
	if (check_line(game.map[0]) == 0)
	{
		free_matrix(game.map);
		ft_printf("Error\nInvalid top!");
		return (0);
	}
	if (check_line(game.map[j - 1]) == 0)
	{
		free_matrix(game.map);
		ft_printf("Error\nInvalid bottom!");
		return (0);
	}
	return (1);
}

static int	previous_check(t_game game, int j, int i, int count_parede)
{
	while (count_parede != j)
	{
		if ((char)game.map[count_parede++][0] != '1')
		{
			free_matrix(game.map);
			ft_printf("Error\nInvalid left side!");
			return (0);
		}
		count_parede--;
		if ((char)game.map[count_parede++][i - 1] != '1')
		{
			free_matrix(game.map);
			ft_printf("Error\nInvalid right side!");
			return (0);
		}
	}
	return (1);
}

static int	check_after_wall(t_game game, int i, int j, char *str)
{
	i = 0;
	while (game.map[i])
	{
		if ((game.map[i][j] >= 32 && game.map[i][j] <= 126)
			|| game.map[i][j] == '\t')
		{
			free(str);
			free_matrix(game.map);
			ft_printf("Error\nChar found out of limits");
			return (0);
		}
		i++;
	}
	free(str);
	return (1);
}

int	check_wall(char **argv)
{
	t_game	game;
	int		count_parede;
	int		i;
	int		j;
	char	*str;

	str = read_map(argv[1]);
	game.map = matriz(str);
	count_parede = 0;
	i = width(game.map) / 50;
	j = height(game.map) / 50;
	if (check_after_wall(game, j, i, str)
		&& previous_check(game, j, i, count_parede)
		&& previous_check_line(game, j))
	{
		free_matrix(game.map);
		return (1);
	}
	else
		return (0);
}
