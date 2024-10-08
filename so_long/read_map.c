/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:23:50 by mebo              #+#    #+#             */
/*   Updated: 2024/08/10 16:23:52 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*read_map(char *src)
{
	char	str[3072];
	int		i;
	int		fd;

	i = 0;
	ft_bzero(str, 3072);
	fd = open(src, 0);
	if (!fd)
		return (NULL);
	while (read(fd, &str[i++], 1) > 0)
		str[i] = 0;
	close(fd);
	if (i >= 3072)
	{
		ft_printf("Error\n");
		ft_printf("Too much chars (Smashing)\n");
		exit(1);
	}
	return (ft_strdup(str));
}
