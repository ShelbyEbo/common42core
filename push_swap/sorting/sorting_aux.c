/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:47:07 by mebo              #+#    #+#             */
/*   Updated: 2024/08/09 16:47:09 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	find_max(t_Stack *p)
{
	t_List	*node;
	int		max;

	node = p->top;
	max = node->value;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	find_last_node(t_Stack *p)
{
	t_List	*node;
	int		last;

	node = p->top;
	while (node != NULL)
	{
		if (node->next == NULL)
			last = node->value;
		node = node->next;
	}
	return (last);
}

int	find_position_of_min(t_Stack *p)
{
	t_List	*node;
	int		pos;
	int		i;
	int		min;

	node = p->top;
	min = node->value;
	pos = 0;
	i = 0;
	while (node != NULL)
	{
		if (min > node->value)
		{
			min = node->value;
			pos = i;
		}
		i++;
		node = node->next;
	}
	return (pos);
}

int	find_min(t_Stack *p)
{
	t_List	*node;
	int		min;

	node = p->top;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

void	min_on_top(t_Stack *p)
{
	t_List	*node;
	int		min;
	int		position;

	node = p->top;
	min = find_min(p);
	position = 0;
	while (node->value != min)
	{
		position++;
		node = node->next;
	}
	if (position <= (ft_count_stack(p) / 2))
	{
		while (position-- > 0)
			ra(p);
	}
	else
	{
		position = ft_count_stack(p) - position;
		while (position-- > 0)
			rra(p);
	}
}
