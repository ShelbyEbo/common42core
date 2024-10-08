/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:38:31 by mebo              #+#    #+#             */
/*   Updated: 2024/05/14 11:38:32 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *src, int chr)
{
	char const	*aux;

	aux = NULL;
	while (*src)
	{
		if (*src == (char)chr)
			aux = src;
		src++;
	}
	if (*src == (char)chr)
		return ((char *)src);
	else
		return ((char *)aux);
}
