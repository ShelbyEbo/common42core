/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <mebo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:47:20 by mebo              #+#    #+#             */
/*   Updated: 2024/09/27 10:28:27 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_sinal_recebido;

void	enviar_sinal(int pid, char enviar)
{
	int				i;

	i = 8;
	while (i > 0)
	{
		g_sinal_recebido = 0;
		i--;
		if (enviar & (1 << i))
		{
			kill(pid, SIGUSR1);
			while (g_sinal_recebido == 0)
				;
		}
		else
		{
			kill(pid, SIGUSR2);
			while (g_sinal_recebido == 0)
				;
		}
	}
}

void	receber_sinal(int sinal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sinal == SIGUSR1 || sinal == SIGUSR2)
		g_sinal_recebido = 1;
	else
		exit(ft_printf("Erro :("));
}

void	checar_argumentos(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(ft_printf("Erro: número de argumentos invalido:(\n"));
	while (argv[1][i] != '\0')
	{
		if (!is_digit(argv[1][i]))
			exit(ft_printf("Erro: PID Ivalido.\n"));
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	sigset_t			set;
	int					pid;
	int					i;

	i = 0;
	checar_argumentos(argc, argv);
	sigemptyset(&set);
	action.sa_handler = NULL;
	action.sa_mask = set;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = receber_sinal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		enviar_sinal(pid, argv[2][i]);
		i++;
	}
	g_sinal_recebido = 0;
}
