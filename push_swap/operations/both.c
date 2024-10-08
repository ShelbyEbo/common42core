/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:42:06 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 09:42:07 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ss(t_Stack *a, t_Stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	rr(t_Stack *a, t_Stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rrr(t_Stack *a, t_Stack *b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
