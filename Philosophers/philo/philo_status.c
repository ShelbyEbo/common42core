/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:56 by mebo              #+#    #+#             */
/*   Updated: 2024/10/03 12:36:31 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	time_start(long time_from_start)
{
	return (get_time_now() - time_from_start);
}

void	smart_sleep(t_lista *l, long time, long current)
{
	t_lista	*first;
	long	start_time;

	first = first_philo(l);
	start_time = get_time_now();
	while (time_start(start_time) < (time / 1000) && simulation_ended(l) != 1)
	{
		if (time_start(l->initial_time) - l->time_last_meal >= l->time_die
			&& l->is_eating == 1)
		{
			pthread_mutex_lock(&first->to_die);
			l->died = 1;
			pthread_mutex_unlock(&first->to_die);
			l = print_status(l, "\033[5;31mdied\n", current);
			return ;
		}
		if (simulation_ended(l) == 1)
			return ;
		usleep(100);
	}
}

int	simulation_ended(t_lista *l)
{
	t_lista	*first;

	first = first_philo(l);
	pthread_mutex_lock(&first->to_stop);
	if (someone_died(l) == 1)
	{
		pthread_mutex_unlock(&first->to_stop);
		return (1);
	}
	if (everyone_ate(l, NULL, NULL) == 1)
	{
		pthread_mutex_unlock(&first->to_stop);
		return (1);
	}
	pthread_mutex_unlock(&first->to_stop);
	return (0);
}

t_lista	*print_status(t_lista *l, char *message, long current)
{
	t_lista	*first;

	first = first_philo(l);
	pthread_mutex_lock(&first->to_print);
	if (simulation_ended(l) == 1)
	{
		printf("\033[1;36m%ld %d %s", get_time_now() - current, l->id,
			message);
		pthread_mutex_unlock(&first->to_print);
		return (l);
	}
	printf("\033[1;36m%ld %d %s", get_time_now() - current, l->id, message);
	pthread_mutex_unlock(&first->to_print);
	return (l);
}
