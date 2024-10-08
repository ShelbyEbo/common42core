/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:56:52 by mebo              #+#    #+#             */
/*   Updated: 2024/09/26 12:47:01 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_lista *l, long current, t_lista *first)
{
	first = first_philo(l);
	if (simulation_ended(l) == 1)
		return ;
	l = print_status(l, "\033[1;32mis eating\n", current);
	l->is_eating = 1;
	smart_sleep(l, l->time_eat, current);
	l->is_eating = 0;
	if (simulation_ended(l) != 1)
	{
		l->time_last_meal = get_time_now();
		if (l->eats > 0)
		{
			pthread_mutex_lock(&first->to_eat);
			l->eats--;
			pthread_mutex_unlock(&first->to_eat);
		}
	}
}

static void	keep_routine(t_lista *l, long current)
{
	t_lista	*first;

	first = first_philo(l);
	if (simulation_ended(l) == 1)
	{
		pthread_mutex_unlock(&l->next->mutex);
		pthread_mutex_unlock(&l->mutex);
		return ;
	}
	if (time_start(l->initial_time) - l->time_last_meal >= l->time_die)
	{
		pthread_mutex_lock(&first->to_die);
		l->died = 1;
		pthread_mutex_unlock(&first->to_die);
		l = print_status(l, "\033[5;31mdied\n", current);
	}
	eat(l, current, NULL);
	pthread_mutex_unlock(&l->next->mutex);
	pthread_mutex_unlock(&l->mutex);
	if (simulation_ended(l) != 1)
		l = print_status(l, "is sleeping\n", current);
	smart_sleep(l, l->time_sleep, current);
}

static void	one_philo_rout(t_lista *l, long current)
{
	l = print_status(l, "has taken a fork\n", current);
	pthread_mutex_lock(&l->mutex);
	usleep(l->time_die * 1000);
	l = print_status(l, "\033[5;31mdied\n", current);
	pthread_mutex_unlock(&l->mutex);
	l->died = 1;
}

void	*routine_2(void *arg)
{
	t_lista	*l;
	long	current;

	l = (t_lista *)arg;
	current = get_time_now();
	l->initial_time = get_time_now();
	while (simulation_ended(l) != 1)
	{
		if (simulation_ended(l) != 1)
			l = print_status(l, "is thinking\n", current);
		if (l->id == l->prev->id)
		{
			one_philo_rout(l, current);
			return (NULL);
		}
		lock_mutexes(l, current);
		keep_routine(l, current);
	}
	return (NULL);
}
