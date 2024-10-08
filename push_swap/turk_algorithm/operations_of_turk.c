/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_of_turk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:53:15 by mebo              #+#    #+#             */
/*   Updated: 2024/08/17 17:53:16 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	find_cost(t_List *n, t_Stack *p, t_Stack *q)
{
	int		i;
	int		cost;

	cost = 0;
	if (position(p, n->value) && position(q, target_b(n->value, q)))
	{
		i = count_rr(q, target_b(n->value, q));
		cost = count_rr(p, n->value);
		if (cost < i)
			cost = i;
	}
	else if (!position(p, n->value) && !position(q, target_b(n->value, q)))
	{
		i = count_rr(q, target_b(n->value, q));
		cost = count_rr(p, n->value);
		if (cost < i)
			cost = i;
	}
	else if (position(p, n->value) != position(q, target_b(n->value, q)))
	{
		cost = count_rr(p, n->value)
			+ count_rr(q, target_b(n->value, q));
	}
	return (cost);
}

int	find_cheapest(t_Stack *p, t_Stack *q)
{
	t_List	*node;
	int		cost;
	int		cheapest;

	node = p->top;
	cost = find_cost(node, p, q);
	cheapest = node->value;
	while (node != NULL)
	{
		if (find_cost(node, p, q) < cost)
		{
			cost = find_cost(node, p, q);
			cheapest = node->value;
		}
		node = node->next;
	}
	return (cheapest);
}

void	do_operations(t_Stack *p, t_Stack *q)
{
	int		i;
	int		cheapest;

	while (ft_count_stack(p) > 0)
	{
		cheapest = find_cheapest(p, q);
		i = target_b(cheapest, q);
		if (position(p, cheapest) && position(q, i))
			while (p->top->value != cheapest && q->top->value != i)
				rr(p, q);
		else if (!position(p, cheapest) && !position(q, i))
			while (p->top->value != cheapest && q->top->value != i)
				rrr(p, q);
		rotating_a(p, cheapest);
		rotating_b(q, i);
		pb(p, q);
	}
	rotating_b(q, find_max(q));
	pa(q, p);
	while (ft_count_stack(q) > 0)
	{
		rotating_a(p, target_a(q->top->value, p));
		pa(q, p);
	}
}
