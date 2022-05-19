/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:15 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/18 22:36:28 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_pid = 0;

void	ft_sigusr_hundle(int sig, siginfo_t *info, void *param)
{
	int			ch;
	static int		i = 7;
	static char		store[9];
	
	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		i = 7;
	}
	param = NULL;
	store[8] = '\0';
	if (sig == SIGUSR2)
	{
		store[i] = '1';
		i--;
	}
	else if (sig == SIGUSR1)
	{
		store[i] = '0';
		i--;
	}
	if (i == -1)
	{
		ch = ft_bin_to_dec(store);
		ft_putchar(ch);
		i = 7;
	}
}

int	main(void)
{
	struct sigaction sa;
	int					pid;
	
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.__sigaction_u.__sa_sigaction = &ft_sigusr_hundle;
	sa.sa_flags = SA_NODEFER;
	sa.sa_flags = SA_SIGINFO;
	while(1)
	{	
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
	}
	return (0);
}