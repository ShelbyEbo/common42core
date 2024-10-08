/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:24:28 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:24:30 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	width(char **matriz)
{
	int	j;

	j = 0;
	while (matriz[0][j])
		j++;
	return (j * 50);
}

int	height(char **matriz)
{
	int	j;

	j = 0;
	while (matriz[j])
		j++;
	return (j * 50);
}

void	free_matrix(char **mtr)
{
	int	i;

	i = -1;
	if (!mtr || !*mtr)
		return ;
	while (mtr[++i] != NULL)
		free(mtr[i]);
	free(mtr);
}

char	**matriz(char *str)
{
	return (ft_split(str, '\n'));
}

int	ft_destroy(t_game *game)
{
	free_matrix(game->map);
	mlx_destroy_image(game->mlx, game->img_colect);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}
