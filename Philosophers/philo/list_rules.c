/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:36:32 by mebo              #+#    #+#             */
/*   Updated: 2024/09/14 15:45:07 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_lista	*create_list(void)
{
	return (NULL);
}

t_lista	*insert_list(t_lista *l, int id, t_lista *aux)
{
	t_lista	*new;

	new = (t_lista *)malloc(sizeof(t_lista));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->id = id;
	if (l)
	{
		aux = l;
		while (aux->next != l)
			aux = aux->next;
		aux->next = new;
		l->prev = new;
		new->prev = aux;
		new->next = l;
	}
	else
	{
		l = new;
		l->prev = new;
		l->next = new;
	}
	return (l);
}

t_lista	*delete_list(t_lista *l)
{
	t_lista	*aux;
	t_lista	*prox;
	t_lista	*first;

	if (!l)
		return (NULL);
	first = l;
	aux = l->next;
	while (aux != first)
	{
		prox = aux->next;
		free(aux);
		aux = prox;
	}
	free(first);
	return (NULL);
}
