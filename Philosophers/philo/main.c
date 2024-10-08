/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:20:04 by mebo              #+#    #+#             */
/*   Updated: 2024/09/26 12:52:48 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philos(t_lista *l, char **argv, int argc)
{
	t_lista	*aux;

	aux = l->next;
	l->time_die = ft_atoi(argv[2]);
	l->time_eat = ft_atoi(argv[3]) * 1000;
	l->time_sleep = ft_atoi(argv[4]) * 1000;
	l->died = 0;
	if (argc == 6)
		l->eats = ft_atoi(argv[5]);
	else
		l->eats = -1;
	while (aux != l)
	{
		aux->time_die = ft_atoi(argv[2]);
		aux->time_eat = ft_atoi(argv[3]) * 1000;
		aux->time_sleep = ft_atoi(argv[4]) * 1000;
		aux->died = 0;
		if (argc == 6)
			aux->eats = ft_atoi(argv[5]);
		else
			aux->eats = -1;
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_lista	*l;

	if (argc < 5 || argc > 6)
		return (-1);
	l = create_list();
	if (argc == 5 || argc == 6)
	{
		if (check_input(argv) && check_error(argv))
		{
			l = insert_positions(l, ft_atoi(argv[1]));
			init_philos(l, argv, argc);
			init_mutexes(l, NULL);
			create_threads(l, NULL);
			join_threads(l, NULL);
			destroy_forks(l, NULL);
			delete_list(l);
		}
		else
			return (-1);
	}
	return (0);
}
