/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:29:58 by mebo              #+#    #+#             */
/*   Updated: 2024/09/26 13:03:12 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_lista	*insert_positions(t_lista *l, int len)
{
	int	i;

	i = 1;
	while (i <= len)
	{
		l = insert_list(l, i, NULL);
		i++;
	}
	return (l);
}

void	destroy_forks(t_lista *l, t_lista *aux)
{
	pthread_mutex_destroy(&l->mutex);
	pthread_mutex_destroy(&l->to_die);
	pthread_mutex_destroy(&l->to_eat);
	pthread_mutex_destroy(&l->to_stop);
	aux = l->next;
	while (aux != l)
	{
		pthread_mutex_destroy(&aux->mutex);
		pthread_mutex_destroy(&aux->to_die);
		pthread_mutex_destroy(&aux->to_eat);
		pthread_mutex_destroy(&aux->to_stop);
		aux = aux->next;
	}
}

void	init_mutexes(t_lista *l, t_lista *aux)
{
	pthread_mutex_init(&l->mutex, NULL);
	pthread_mutex_init(&l->to_die, NULL);
	pthread_mutex_init(&l->to_eat, NULL);
	pthread_mutex_init(&l->to_stop, NULL);
	pthread_mutex_init(&l->to_print, NULL);
	aux = l->next;
	while (aux != l)
	{
		pthread_mutex_init(&aux->mutex, NULL);
		pthread_mutex_init(&aux->to_die, NULL);
		pthread_mutex_init(&aux->to_eat, NULL);
		pthread_mutex_init(&aux->to_stop, NULL);
		pthread_mutex_init(&aux->to_print, NULL);
		aux = aux->next;
	}
}

void	create_threads(t_lista *l, t_lista *aux)
{
	pthread_create(&l->philo, NULL, routine_2, (void *)l);
	aux = l->next;
	while (aux != l)
	{
		pthread_create(&aux->philo, NULL, routine_2, (void *)aux);
		aux = aux->next;
	}
}

void	join_threads(t_lista *l, t_lista *aux)
{
	pthread_join(l->philo, NULL);
	aux = l->next;
	while (aux != l)
	{
		pthread_join(aux->philo, NULL);
		aux = aux->next;
	}
}
