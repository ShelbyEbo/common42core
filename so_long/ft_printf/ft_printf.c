/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:21:53 by mebo              #+#    #+#             */
/*   Updated: 2024/05/22 09:21:54 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	imprimeform(va_list args, const char *joisson, int *tamanho)
{
	if (*joisson == 'c')
		ft_putchar(va_arg(args, int), tamanho);
	else if (*joisson == 's')
		ft_putstr(va_arg(args, char *), tamanho);
	else if (*joisson == 'd' || *joisson == 'i')
		ft_putnbr(va_arg(args, int), tamanho);
	else if (*joisson == 'x')
		ft_puthexlow(va_arg(args, unsigned int), tamanho);
	else if (*joisson == 'X')
		ft_puthexupp(va_arg(args, unsigned int), tamanho);
	else if (*joisson == 'u')
		ft_putunbr(va_arg(args, unsigned int), tamanho);
	else if (*joisson == 'p')
		ft_putptr(va_arg(args, void *), tamanho);
	else if (*joisson == '%')
		ft_putchar('%', tamanho);
}

int	ft_printf(const char *joisson, ...)
{
	va_list	args;
	int		print;

	print = 0;
	va_start(args, joisson);
	while (*joisson)
	{
		if (*joisson == '%')
		{
			joisson++;
			imprimeform(args, joisson, &print);
		}
		else
			ft_putchar(*joisson, &print);
		joisson++;
	}
	va_end(args);
	return (print);
}
