/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:22:32 by mebo              #+#    #+#             */
/*   Updated: 2024/05/22 09:22:34 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, int *tamanho);
void	ft_putstr(char *str, int *tamanho);
void	ft_putnbr(int n, int *tamanho);
void	ft_putunbr(unsigned int n, int *tamanho);
void	ft_puthexlow(unsigned int n, int *tamanho);
void	ft_puthexupp(unsigned int n, int *tamanho);
void	ft_putptr(void *ptr, int *tamanho);

int		ft_printf(const char *joisson, ...);

#endif
