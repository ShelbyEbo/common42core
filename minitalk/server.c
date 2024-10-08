/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:56:21 by mebo              #+#    #+#             */
/*   Updated: 2024/09/27 09:31:54 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receber_sinal(int sinal, siginfo_t *info, void *context)
{
	static unsigned char	chr;
	static int				i;

	(void)context;
	if (sinal == SIGUSR1)
		chr |= 1;
	i++;
	if (i == 8)
	{
		if (chr == '\0')
			write(1, "\n", 1);
		else
			write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
	else
		chr = chr << 1;
	if (sinal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sinal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	lead;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	lead.sa_handler = NULL;
	lead.sa_mask = set;
	lead.sa_flags = SA_SIGINFO;
	lead.sa_sigaction = ft_receber_sinal;
	sigaction(SIGUSR1, &lead, NULL);
	sigaction(SIGUSR2, &lead, NULL);
	primeiro();
	ft_printf("Powered by: Melzira Ebo :D \n");
	ft_printf("[");
	ft_printf("PID: %d", getpid());
	ft_printf("]\n");
	while (1)
		pause();
}
