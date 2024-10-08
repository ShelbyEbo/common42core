/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_auxs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:22:56 by mebo              #+#    #+#             */
/*   Updated: 2024/08/09 17:22:58 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	position(t_Stack *p, int value)
{
	t_List	*node;
	int		middle;
	int		i;

	i = 0;
	middle = ft_count_stack(p) / 2;
	node = p->top;
	while (node->value != value)
	{
		node = node->next;
		i++;
	}
	if (i <= middle)
		return (1);
	else
		return (0);
}

int	count_rr(t_Stack *p, int value)
{
	t_List	*node;
	int		middle;
	int		i;

	i = 0;
	middle = ft_count_stack(p) / 2;
	node = p->top;
	while (node->value != value)
	{
		node = node->next;
		i++;
	}
	if (i <= middle)
		return (i);
	else
		return (ft_count_stack(p) - i);
}

void	rotating_a(t_Stack *a, int value)
{
	int	i;

	i = count_rr(a, value);
	if (position(a, value) == 1)
	{
		while (i-- > 0)
			ra(a);
	}
	else
	{
		while (i-- > 0)
			rra(a);
	}
}

void	rotating_b(t_Stack *b, int value)
{
	int	i;

	i = count_rr(b, value);
	if (position(b, value) == 1)
	{
		while (i-- > 0)
			rb(b);
	}
	else
	{
		while (i-- > 0)
			rrb(b);
	}
}
