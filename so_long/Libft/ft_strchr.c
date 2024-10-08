/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:48:06 by mebo              #+#    #+#             */
/*   Updated: 2024/05/14 10:48:07 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *src, int chr)
{
	while (*src)
	{
		if (*src == (char)chr)
			return ((char *)src);
		src++;
	}
	if (chr == '\0')
		return ((char *)src);
	return (NULL);
}
