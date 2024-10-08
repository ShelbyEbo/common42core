/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personalizar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mebo              #+#    #+#             */
/*   Updated: 2024/07/23 14:59:03 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	primeiro(void)
{
	int	i;

	i = 0;
	ft_printf("---------------\n");
	while (i <= 10)
	{
		if (i == 3)
			ft_printf("|Welcome      |\n");
		else if (i == 5)
			ft_printf("|     to      |\n");
		else if (i == 7)
			ft_printf("|     Minitalk|\n");
		else
			ft_printf("|             |\n");
		i++;
	}
	ft_printf("---------------\n");
}
