/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_error_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:55:38 by mebo              #+#    #+#             */
/*   Updated: 2024/08/17 12:55:39 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != '1')
			return (0);
	}
	return (1);
}

int	check_double_new_line(char **argv)
{
	char	*str;
	int		i;

	str = read_map(argv[1]);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| str[0] == '\n')
		{
			free(str);
			ft_printf("Error\nEmpty line or map!");
			return (0);
		}
		i++;
	}
	free(str);
	return (1);
}
