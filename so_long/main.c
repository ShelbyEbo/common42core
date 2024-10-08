/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:25:51 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:25:52 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	check_map_name(const char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map %s nonexistent", str);
		exit(EXIT_SUCCESS);
	}
	close(fd);
}

static void	check_in(char **args, t_game game, char *str)
{
	if (check_map(args) && check_wall(args) && check_is_not_stuck(&game))
	{
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx,
				width(game.map), height(game.map), "so_long");
		show_map(&game);
		free(str);
		free_matrix(game.map_copy);
		free_matrix(game.map_exit);
		mlx_key_hook(game.win, keypress, &game);
		mlx_hook(game.win, 17, 1L << 0, ft_destroy, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		free_matrix(game.map);
		free_matrix(game.map_copy);
		free_matrix(game.map_exit);
		free(str);
		exit(1);
	}
}

static void	free_first_line(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		ft_printf("Error\nEmpty map");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str;
	char	**args;

	if (argc != 2)
		exit(ft_printf("Invalid arguments!"));
	check_map_name(argv[1]);
	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		args = argv;
		if (!check_error(args))
			exit(1);
		str = read_map(args[1]);
		free_first_line(str);
		game.map = matriz(str);
		game.map_copy = matriz(str);
		game.map_exit = matriz(str);
		game.items_count = count_chars(&game, 'C');
		check_in(args, game, str);
	}
	return (0);
}
