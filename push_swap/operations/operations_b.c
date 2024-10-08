/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:42:00 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 09:42:01 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sb(t_Stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	pb(t_Stack *a, t_Stack *b)
{
	push_o(a, b);
	ft_printf("pb\n");
}

void	rb(t_Stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rrb(t_Stack *b)
{
	rrotate(b);
	ft_printf("rrb\n");
}
