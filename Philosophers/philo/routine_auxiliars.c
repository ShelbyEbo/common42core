/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_auxiliars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:10:08 by mebo              #+#    #+#             */
/*   Updated: 2024/09/26 08:32:01 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	lock_mutexes(t_lista *l, long current)
{
	(void)current;
	if (l->id % 2 != 0)
		usleep(100);
	if (l->id % 2 == 0)
	{
		pthread_mutex_lock(&l->mutex);
		if (simulation_ended(l) != 1)
			l = print_status(l, "\033[1;36mhas taken a fork\n", current);
		pthread_mutex_lock(&l->next->mutex);
		if (simulation_ended(l) != 1)
			l = print_status(l, "\033[1;36mhas taken a fork\n", current);
	}
	else
	{
		pthread_mutex_lock(&l->next->mutex);
		if (simulation_ended(l) != 1)
			l = print_status(l, "\033[1;36mhas taken a fork\n", current);
		pthread_mutex_lock(&l->mutex);
		if (simulation_ended(l) != 1)
			l = print_status(l, "\033[1;36mhas taken a fork\n", current);
	}
}

int	someone_died(t_lista *l)
{
	t_lista	*aux;
	t_lista	*first;

	first = first_philo(l);
	pthread_mutex_lock(&first->to_die);
	if (l->died != 0)
	{
		pthread_mutex_unlock(&first->to_die);
		return (1);
	}
	aux = l->next;
	while (aux != l)
	{
		if (aux->died != 0)
		{
			pthread_mutex_unlock(&first->to_die);
			return (1);
		}
		aux = aux->next;
	}
	pthread_mutex_unlock(&first->to_die);
	return (0);
}

int	everyone_ate(t_lista *l, t_lista *aux, t_lista *first)
{
	first = first_philo(l);
	pthread_mutex_lock(&first->to_eat);
	if (l->eats == -1)
	{
		pthread_mutex_unlock(&first->to_eat);
		return (0);
	}
	if (l->eats > 0)
	{
		pthread_mutex_unlock(&first->to_eat);
		return (0);
	}
	aux = l->next;
	while (aux != l)
	{
		if (aux->eats > 0)
		{
			pthread_mutex_unlock(&first->to_eat);
			return (0);
		}
		aux = aux->next;
	}
	pthread_mutex_unlock(&first->to_eat);
	return (1);
}

t_lista	*first_philo(t_lista *l)
{
	t_lista	*aux;

	aux = l->next;
	if (l->id == 1)
		return (l);
	while (aux != l)
	{
		if (aux->id == 1)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}
