/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:43:08 by mebo              #+#    #+#             */
/*   Updated: 2024/05/15 09:43:09 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		sizelil;

	if (!*little)
		return ((char *)big);
	sizelil = ft_strlen(little);
	while (*big && len >= sizelil)
	{
		if (*big == *little && ft_strncmp(big, little, sizelil) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
