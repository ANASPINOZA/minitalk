/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:51:30 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/22 20:54:33 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		i;
	int		pid;

	if (ac != 3)
		write(1, "Invalid Usage: ./client [PID] (Message)\n", 41);
	else
	{
		pid = ft_atoi(av[1]);
		if (pid > 0)
		{
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
		else
			write(1, "Invalide pid !!\n", 18);
	}
	return (0);
}
