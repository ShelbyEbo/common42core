/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:14:19 by mebo              #+#    #+#             */
/*   Updated: 2024/07/23 14:14:20 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_Stack	*create(void)
{
	t_Stack	*p;

	p = (t_Stack *)malloc(sizeof(t_Stack));
	if (p != NULL)
		p->top = NULL;
	else
		ft_printf("Error\n");
	return (p);
}

void	push(t_Stack *p, int value)
{
	t_List	*node;

	if (p)
	{
		node = (t_List *)malloc(sizeof(t_List));
		if (node)
		{
			node->value = value;
			node->next = p->top;
			p->top = node;
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
}

int	pop(t_Stack *p)
{
	int		k;
	t_List	*aux;

	k = 0;
	if (p)
	{
		if (p->top)
		{
			aux = p->top;
			p->top = aux->next;
			k = aux->value;
			free(aux);
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (k);
}

void	print_stack(t_Stack *p)
{
	t_List	*aux;

	if (!p)
		ft_printf("Vazio");
	else
	{
		if (p->top)
		{
			aux = p->top;
			while (aux)
			{
				ft_printf("%d\n", aux->value);
				aux = aux->next;
			}
		}
		else
			ft_printf("Vazio");
	}
}

t_Stack	*delete_stack(t_Stack *p)
{
	while (p->top)
		pop(p);
	free(p);
	return (NULL);
}
