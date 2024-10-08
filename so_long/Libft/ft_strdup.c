/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:36:33 by mebo              #+#    #+#             */
/*   Updated: 2024/05/15 11:36:34 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *dup, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(str) + 1);
	if (duplicate != NULL)
		ft_strcpy(duplicate, (char *)str);
	return (duplicate);
}
