/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:20:33 by mebo              #+#    #+#             */
/*   Updated: 2024/05/17 10:20:33 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 4294967295;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > size_max / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
