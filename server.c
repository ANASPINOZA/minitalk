/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:15 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/30 11:54:37 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	ft_print_char(int *i, int *res)
{
	if (*i == 8)
	{
		ft_putchar(*res);
		*res = 0;
		*i = 0;
	}
}

void	ft_sigusr_hundle(int sig, siginfo_t *info, void *param)
{
	static int		i;
	static int		res;

	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		res = 0;
		i = 0;
	}
	(void)param;
	if (sig == SIGUSR2)
	{
		res = res * 2;
		res = res + 1;
		i++;
		ft_print_char(&i, &res);
	}
	else
	{
		res = res * 2;
		res = res + 0;
		i++;
		ft_print_char(&i, &res);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.__sigaction_u.__sa_sigaction = &ft_sigusr_hundle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{	
		pause();
	}
	return (0);
}
