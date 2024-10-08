/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:23:08 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 13:23:09 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(char **argv, int value, int i)
{
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == value)
			return (0);
	}
	return (1);
}

int	is_sorted(t_Stack *p)
{
	t_List	*aux;

	aux = p->top;
	while (aux->next)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	char_limit(char *str)
{
	long	value;

	value = ft_atol(str);
	if ((value > INT_MAX) || (value < INT_MIN))
		return (0);
	return (1);
}

void	print_error(t_Stack *p)
{
	freers(p);
	exit(ft_printf("Error\n"));
}
