/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_auxs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:33:19 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 13:33:20 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	freers(t_Stack *p)
{
	t_List	*aux;
	t_List	*curr;

	aux = p->top;
	while (aux)
	{
		curr = aux->next;
		free(aux);
		aux = curr;
	}
	free(p);
}

int	is_empty(t_Stack *p)
{
	return (p->top == NULL);
}

int	ft_count_stack(t_Stack *p)
{
	t_List	*node;
	int		i;

	i = 0;
	node = p->top;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	fill_2(char **args, t_Stack *p, t_Stack *q)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_dups(args, ft_atoi(args[i]), i)
			&& check_digit(args[i]) && char_limit(args[i]))
			i++;
		else
		{
			free(q);
			desalocate(args);
			print_error(p);
		}
	}
	while (i-- > 0)
		push(p, ft_atoi(args[i]));
	if (is_sorted(p))
		desalocate(args);
}

void	fill_stack(int argc, char **argv, t_Stack *p, t_Stack *q)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_dups(argv, ft_atoi(argv[i]), i)
			&& check_digit(argv[i]) && char_limit(argv[i]))
			i++;
		else
		{
			free(q);
			print_error(p);
		}
	}
	i = argc;
	while (--i > 0)
		push(p, ft_atoi(argv[i]));
}
