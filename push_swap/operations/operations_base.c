/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:41:32 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 09:41:33 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	swap(t_Stack *p)
{
	t_List	*node;
	int		temp;

	node = p->top;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
}

void	push_o(t_Stack *p1, t_Stack *p2)
{
	int	aux;

	if (!p2)
		p2 = create();
	aux = pop(p1);
	push(p2, aux);
}

void	rotate(t_Stack *p)
{
	t_List	*seg;
	int		aux;

	seg = p->top;
	aux = seg->value;
	while (seg->next)
	{
		seg->value = seg->next->value;
		seg = seg->next;
	}
	seg->value = aux;
}

void	rrotate(t_Stack *p)
{
	t_List	*node;
	t_List	*ant;

	node = p->top;
	ant = NULL;
	while (node->next)
	{
		ant = node;
		node = node->next;
	}
	if (ant)
		ant->next = NULL;
	node->next = p->top;
	p->top = node;
}
