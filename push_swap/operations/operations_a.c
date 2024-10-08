/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:41:55 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 09:41:56 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sa(t_Stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	pa(t_Stack *b, t_Stack *a)
{
	push_o(b, a);
	ft_printf("pa\n");
}

void	ra(t_Stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rra(t_Stack *a)
{
	rrotate(a);
	ft_printf("rra\n");
}
