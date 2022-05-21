/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:15 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/21 14:56:06 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	ft_print_char(int *i, int *result)
{
	if (*i == 8)
	{
		ft_putchar(*result);
		*result = 0;
		*i = 0;
	}
}

void	ft_sigusr_hundle(int sig, siginfo_t *info, void *param)
{
	static int		i;
	static int		res;
	
	// static char		store[9];
	// store[8] = '\0';
	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		res = 0;
		i = 0;
	}
	(void)param;
	if (sig == SIGUSR2)
	{
		// store[i--] = '1';
		res = res * 2;
		res = res + 1;
		i++;
		ft_print_char(&i, &res);
	}
	else
	{
		// store[i--] = '0';
		res = res * 2;
		res = res + 0;
		i++;
		ft_print_char(&i, &res);
	}
	// if (i == 8)
	// {
	// 	// ft_putchar(ft_bin_to_dec(store));
	// 	ft_bzero(store, 8);
	// 	i = 7;
	// }
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
	while (1)
	{	
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
	}
	return (0);
}
