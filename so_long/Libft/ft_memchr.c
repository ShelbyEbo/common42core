/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:18:19 by mebo              #+#    #+#             */
/*   Updated: 2024/05/17 10:18:19 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				tf;

	ptr = (const unsigned char *)s;
	tf = (char) c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == tf)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
