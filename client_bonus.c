/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:14:37 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/22 14:41:41 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	respond_handle(int sig, siginfo_t *param1, void *param2)
{
	(void)param1;
	(void)param2;
	if (sig == SIGUSR1)
		write(1, "the message has received\n", 25);
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	respond;

	if (ac != 3)
		write(1, "Invalid Usage: ./client [ID] (Message)\n", 40);
	else
	{
		respond.__sigaction_u.__sa_sigaction = &respond_handle;
		respond.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &respond, NULL);
		pid = ft_atoi(av[1]);
		if (ac == 3)
		{
		i = 0;
			while (av[2][i])
			{
				ft_dec_to_bin(av[2][i], pid);
					i++;
			}
			ft_dec_to_bin(av[2][i], pid);
		}		
	}
	return (0);
}
