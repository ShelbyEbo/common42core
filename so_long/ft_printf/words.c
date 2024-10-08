/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:37:14 by mebo              #+#    #+#             */
/*   Updated: 2024/05/28 07:37:15 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(char *str, int *tamanho)
{
	if (str == NULL)
		ft_putstr("(null)", tamanho);
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			(*tamanho)++;
		}
	}
}

void	ft_putchar(char c, int *tamanho)
{
	write(1, &c, 1);
	(*tamanho)++;
}
