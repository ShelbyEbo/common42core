/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:27:30 by mebo              #+#    #+#             */
/*   Updated: 2024/08/14 14:27:31 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	target_b(int a_value, t_Stack *b)
{
	t_List	*cur_b;
	int		target;

	target = INT_MIN;
	cur_b = b->top;
	while (cur_b != NULL)
	{
		if (cur_b->value < a_value && cur_b->value > target)
			target = cur_b->value;
		cur_b = cur_b->next;
	}
	if (target == INT_MIN)
		return (find_max(b));
	return (target);
}

int	target_a(int b_value, t_Stack *a)
{
	t_List	*cur_a;
	int		target;

	target = INT_MAX;
	cur_a = a->top;
	while (cur_a != NULL)
	{
		if (cur_a->value > b_value && cur_a->value < target)
			target = cur_a->value;
		cur_a = cur_a->next;
	}
	if (target == INT_MAX)
		return (find_min(a));
	return (target);
}
