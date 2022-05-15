/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:51:30 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/14 19:14:22 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		i;
	int		pid;

	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		i = 0;
		while (av[2][i])
		{
			ft_dec_to_bin(av[2][i], pid);
			// if (av[2][i] == '1')
			// {
			// 	kill(pid, SIGUSR2);
			// }
			// else if (av[2][i] == '0')
			// {
			// 	kill(pid, SIGUSR1);
			// }
			i++;
			// usleep(600);
		}
	}
	return (0);
}