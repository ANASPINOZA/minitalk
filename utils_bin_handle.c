/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bin_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:02:21 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/22 20:10:20 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_dec_to_bin(char c, int pid)
{
	unsigned int		i;
	unsigned int		base;
	unsigned int		res;

	i = 0;
	base = 0b10000000;
	while (i < 8)
	{
		res = base & c;
		if (res == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (800);
		c = c << 1;
		i++;
	}
}
