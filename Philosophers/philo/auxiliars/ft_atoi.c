/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:19:46 by mebo              #+#    #+#             */
/*   Updated: 2024/05/17 10:19:47 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "aux.h"

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	return (result * sign);
}
