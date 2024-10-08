/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:37:23 by mebo              #+#    #+#             */
/*   Updated: 2024/05/28 07:37:24 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *tamanho)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10, tamanho);
		ft_putchar(n % 10 + '0', tamanho);
	}
	else
		ft_putchar(n + '0', tamanho);
}

void	ft_putnbr(int n, int *tamanho)
{
	if (n == -2147483648)
	{
		ft_putchar('-', tamanho);
		ft_putstr("2147483648", tamanho);
	}
	else if (n < 0)
	{
		ft_putchar('-', tamanho);
		ft_putnbr(n * -1, tamanho);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, tamanho);
		ft_putchar(n % 10 + '0', tamanho);
	}
	else
		ft_putchar(n + '0', tamanho);
}
