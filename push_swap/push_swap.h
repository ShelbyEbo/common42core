/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:05:55 by mebo              #+#    #+#             */
/*   Updated: 2024/07/23 14:05:56 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libftaux/aux.h"

typedef struct list
{
	int				value;
	struct list		*next;
}					t_List;

typedef struct stack
{
	t_List			*top;
}				t_Stack;

//Errors
int			check_digit(char *str);
int			check_dups(char **argv, int value, int i);
int			char_limit(char *str);
int			ft_isspace(const char *str, int i);
int			ft_isdigit(int c);

//Utils
long int	ft_atol(const char *str);

//Turk algorithm
int			target_b(int a_value, t_Stack *b);
int			target_a(int b_value, t_Stack *a);
int			find_cost(t_List *n, t_Stack *p, t_Stack *q);
int			position(t_Stack *p, int value);
int			count_rr(t_Stack *p, int value);
int			find_cheapest(t_Stack *p, t_Stack *q);
void		do_operations(t_Stack *p, t_Stack *q);
void		rotating_a(t_Stack *a, int value);
void		rotating_b(t_Stack *b, int value);

//Stack rules
t_Stack		*create(void);
t_Stack		*delete_stack(t_Stack *p);
void		push(t_Stack *p, int value);
void		print_stack(t_Stack *p);
int			pop(t_Stack *p);

//Stack auxs
int			ft_count_stack(t_Stack *p);
int			is_empty(t_Stack *p);
void		fill_2(char **argv, t_Stack *p, t_Stack *q);
void		fill_stack(int argc, char **argv, t_Stack *p, t_Stack *q);

//Operations base
void		swap(t_Stack *p);
void		rotate(t_Stack *p);
void		push_o(t_Stack *p1, t_Stack *p2);
void		rrotate(t_Stack *p);

//Operations a
void		sa(t_Stack *a);
void		pa(t_Stack *b, t_Stack *a);
void		ra(t_Stack *a);
void		rra(t_Stack *a);

//Operations b
void		sb(t_Stack *b);
void		pb(t_Stack *a, t_Stack *b);
void		rb(t_Stack *b);
void		rrb(t_Stack *b);

//Both
void		ss(t_Stack *a, t_Stack *b);
void		rr(t_Stack *a, t_Stack *b);
void		rrr(t_Stack *a, t_Stack *b);

//Sorting
void		sorting_3(t_Stack *p);
void		sorting_4(t_Stack *p, t_Stack *q);
void		sorting_5(t_Stack *p, t_Stack *q);
void		sorting_plus(t_Stack *p, t_Stack *q);
void		sorting_stack(t_Stack *p, t_Stack *q);

//Sorting auxs
void		check_order(t_Stack *p, t_Stack *q);
void		min_on_top(t_Stack *p);
int			is_sorted(t_Stack *p);
int			find_max(t_Stack *p);
int			find_min(t_Stack *p);
int			find_position_of_min(t_Stack *p);

//Free
void		desalocate(char **args);
void		freers(t_Stack *p);
void		print_error(t_Stack *p);

#endif
