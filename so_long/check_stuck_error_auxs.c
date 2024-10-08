/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuck_error_auxs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:09 by mebo              #+#    #+#             */
/*   Updated: 2024/08/20 15:24:09 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	flood_fill_exit(char **map, int x, int y, int *reachable)
{
	if (x < 0 || x >= width(map) / 50 || y < 0 || y >= height(map) / 50)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
		(*reachable)++;
	map[y][x] = 'F';
	flood_fill_exit(map, x + 1, y, reachable);
	flood_fill_exit(map, x - 1, y, reachable);
	flood_fill_exit(map, x, y + 1, reachable);
	flood_fill_exit(map, x, y - 1, reachable);
}

void	flood_fill(char **map, int x, int y, int *reachable)
{
	if (x < 0 || x >= width(map) / 50 || y < 0 || y >= height(map) / 50)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		(*reachable)++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, reachable);
	flood_fill(map, x - 1, y, reachable);
	flood_fill(map, x, y + 1, reachable);
	flood_fill(map, x, y - 1, reachable);
}

void	player_flood_fill(char **map_copy, t_point point, int *acess)
{
	int	y;
	int	x;

	y = 0;
	while (y < point.y)
	{
		x = 0;
		while (x < point.x)
		{
			if (map_copy[y][x] == 'P')
			{
				flood_fill(map_copy, x, y, acess);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	player_flood_fill_exit(char **map_exit, t_point point, int *acess)
{
	int	y;
	int	x;

	y = 0;
	while (y < point.y)
	{
		x = 0;
		while (x < point.x)
		{
			if (map_exit[y][x] == 'P')
			{
				flood_fill_exit(map_exit, x, y, acess);
				return ;
			}
			x++;
		}
		y++;
	}
}
