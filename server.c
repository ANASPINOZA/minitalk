/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:15 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/15 14:03:53 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	ft_sigusr_hundle(int sig)
{
	char			ch;
	static int		i = 7;	
	static char		store[9];

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

// void	ft_sigusr_hundle(int sig, siginfo_t *info, void *param)
// {
// 	static int		i;
// 	char			ch;
// 	char			store[9];

// 	if (sig == SIGUSR2)
// 		store[i] = '1';
// 	else if (sig == SIGUSR1)
// 		store[i] = '0';
// 	i++;
// 	if (i == 8)
// 	{
// 		store[i] = 0;
// 		ch = ft_bin_to_dec(store);
// 		ft_putchar(ch);
// 		i = 0;
// 	}

// }

// int	main(void)
// {
// 	struct sigaction sa;
// 	int					pid;
	
// 	pid = getpid();
// 	ft_putnbr(pid);
// 	ft_putchar('\n');
// 	sa.__sigaction_u.__sa_sigaction = &ft_sigusr_hundle;
// 	sa.sa_flags = SIGINFO;

// 	while(1)
// 	{	
// 		sigaction(SIGUSR2, &sa, NULL);
// 		sigaction(SIGUSR1, &sa, NULL);
		
// 	}
// 	return (0);
// }

int	main(void)
{
	struct sigaction sa;
	int					pid;
	
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_handler = &ft_sigusr_hundle;
	sa.sa_flags = SA_NODEFER;
	// sa.sa_flags = SIGINFO;

	while(1)
	{	
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
	}
	return (0);
}