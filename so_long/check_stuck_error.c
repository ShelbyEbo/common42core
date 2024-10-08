/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuck_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:40:14 by mebo              #+#    #+#             */
/*   Updated: 2024/08/20 15:40:15 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_is_stuck_exit(char **map_exit, t_point point)
{
	int	x;
	int	y;

	y = 0;
	while (y < point.y)
	{
		x = 0;
		while (x < point.x)
		{
			if (map_exit[y][x] == 'E')
			{
				if (map_exit[y][x] != 'F')
				{
					ft_printf("Error\nStuck Exit or Player");
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_is_stuck_item(char **map_copy, t_point point)
{
	int	x;
	int	y;

	y = 0;
	while (y < point.y)
	{
		x = 0;
		while (x < point.x)
		{
			if (map_copy[y][x] == 'C')
			{
				if (map_copy[y][x] != 'F')
				{
					ft_printf("Error\nStuck item");
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_exit_acessible(t_game *game)
{
	t_point	point;
	int		acess;
	int		result;

	point.x = width(game->map) / 50;
	point.y = height(game->map) / 50;
	acess = 0;
	player_flood_fill_exit(game->map_exit, point, &acess);
	result = check_is_stuck_exit(game->map_exit, point);
	return (result);
}

int	check_collectible_acessible(t_game *game)
{
	t_point	point;
	int		acess;
	int		result;

	point.x = width(game->map) / 50;
	point.y = height(game->map) / 50;
	acess = 0;
	player_flood_fill(game->map_copy, point, &acess);
	result = check_is_stuck_item(game->map_copy, point);
	return (result);
}

int	check_is_not_stuck(t_game *game)
{
	if (check_exit_acessible(game) && check_collectible_acessible(game))
		return (1);
	else
	{
		return (0);
	}
}
