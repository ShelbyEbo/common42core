/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:37:32 by mebo              #+#    #+#             */
/*   Updated: 2024/05/28 07:37:33 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_puthex(unsigned long long n, int *tamanho)
{
	if (n >= 16)
		ft_puthex(n / 16, tamanho);
	ft_putchar("0123456789abcdef"[n % 16], tamanho);
}

void	ft_putptr(void *ptr, int *tamanho)
{
	if (ptr == 0)
		ft_putstr("(nil)", tamanho);
	else
	{
		ft_putstr("0x", tamanho);
		ft_puthex((unsigned long long)ptr, tamanho);
	}
}

void	ft_puthexupp(unsigned int n, int *tamanho)
{
	if (n >= 16)
		ft_puthexupp(n / 16, tamanho);
	ft_putchar("0123456789ABCDEF"[n % 16], tamanho);
}

void	ft_puthexlow(unsigned int n, int *tamanho)
{
	if (n >= 16)
		ft_puthexlow(n / 16, tamanho);
	ft_putchar("0123456789abcdef"[n % 16], tamanho);
}
