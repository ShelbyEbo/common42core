/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:35 by mebo              #+#    #+#             */
/*   Updated: 2024/07/23 14:39:35 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	ret;
	int	sig;

	i = 0;
	ret = 0;
	sig = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * sig);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	putchar_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
