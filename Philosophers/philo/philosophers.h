/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:10:52 by mebo              #+#    #+#             */
/*   Updated: 2024/09/26 12:53:31 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "auxiliars/aux.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_list
{
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				eats;
	int				is_eating;
	int				died;
	int				id;
	long			time_last_meal;
	long			initial_time;
	pthread_t		philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	to_die;
	pthread_mutex_t	to_print;
	pthread_mutex_t	to_eat;
	pthread_mutex_t	to_stop;
	struct s_list	*prev;
	struct s_list	*next;
}					t_lista;

// Errors
int					check_error(char **argv);
int					check_input(char **argv);

// Inceptions
t_lista				*create_list(void);
t_lista				*insert_list(t_lista *l, int id, t_lista *aux);
t_lista				*delete_list(t_lista *l);
t_lista				*insert_positions(t_lista *l, int len);
t_lista				*print_status(t_lista *l, char *message, long current);
void				init_mutexes(t_lista *l, t_lista *aux);
void				destroy_forks(t_lista *l, t_lista *aux);
void				join_threads(t_lista *l, t_lista *aux);
void				create_threads(t_lista *l, t_lista *aux);

// Auxiliars
t_lista				*first_philo(t_lista *l);
long				get_time_now(void);
long				time_start(long time_from_start);
void				lock_mutexes(t_lista *l, long current);
int					check_philo_death(t_lista *l);
int					someone_died(t_lista *l);
int					everyone_ate(t_lista *l, t_lista *aux, t_lista *first);
int					simulation_ended(t_lista *l);
void				smart_sleep(t_lista *l, long time, long current);

// Obrigations
void				*routine(void *arg);
void				*routine_2(void *arg);

#endif