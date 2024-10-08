/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:03:43 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 14:03:44 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	desalocate(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	check_order(t_Stack *p, t_Stack *q)
{
	if (!is_sorted(p))
	{
		if (ft_count_stack(p) == 2)
			sa(p);
		else if (ft_count_stack(p) == 3)
			sorting_3(p);
		else
			sorting_stack(p, q);
	}
	else
	{
		freers(p);
		freers(q);
		exit(1);
	}	
}

static void	init_stacks(t_Stack **p, t_Stack **q)
{
	*p = create();
	*q = create();
	if (!*p || !*q)
	{
		freers(*p);
		freers(*q);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_Stack	*p;
	t_Stack	*q;
	char	**args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	init_stacks(&p, &q);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		fill_2(args, p, q);
	}
	if (argc > 2)
		fill_stack(argc, argv, p, q);
	check_order(p, q);
	freers(p);
	freers(q);
	if (argc == 2)
		desalocate(args);
}
