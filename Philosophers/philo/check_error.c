/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:22:06 by mebo              #+#    #+#             */
/*   Updated: 2024/09/13 13:27:53 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_error(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1
		|| ft_atoi(argv[4]) < 1)
		return (0);
	else if (argv[5])
	{
		if (ft_atoi(argv[5]) < 1)
			return (0);
	}
	return (1);
}
