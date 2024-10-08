/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:59 by mebo              #+#    #+#             */
/*   Updated: 2024/07/23 14:40:00 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <signal.h>

size_t	ft_strlen(const char *str);

int		ft_atoi(char *str);
int		is_digit(int c);

void	putstr_fd(char *str, int fd);
void	primeiro(void);

#endif
