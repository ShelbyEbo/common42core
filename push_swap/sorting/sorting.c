/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:21:10 by mebo              #+#    #+#             */
/*   Updated: 2024/07/29 15:21:11 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sorting_3(t_Stack *p)
{
	t_List	*node;
	int		max;

	node = p->top;
	max = find_max(p);
	if (node->value == max)
		ra(p);
	else if (node->next->value == max)
		rra(p);
	if (node->value > node->next->value)
		sa(p);
}

void	sorting_4(t_Stack *p, t_Stack *q)
{
	int		pos;

	pos = find_position_of_min(p);
	if (pos == 1)
		sa(p);
	else if (pos == 2)
	{
		ra(p);
		sa(p);
	}
	else if (pos == 3)
		rra(p);
	pb(p, q);
	sorting_3(p);
	pa(q, p);
}

void	sorting_5(t_Stack *p, t_Stack *q)
{
	min_on_top(p);
	pb(p, q);
	if (ft_count_stack(p) == 3)
		sorting_3(p);
	else if (ft_count_stack(p) == 4)
		sorting_4(p, q);
	pa(q, p);
}

void	sorting_plus(t_Stack *p, t_Stack *q)
{
	pb(p, q);
	pb(p, q);
	do_operations(p, q);
}

void	sorting_stack(t_Stack *p, t_Stack *q)
{
	if (ft_count_stack(p) == 4)
		sorting_4(p, q);
	if (ft_count_stack(p) == 5)
		sorting_5(p, q);
	else
		sorting_plus(p, q);
}
