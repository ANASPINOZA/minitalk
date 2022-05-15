/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bin_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:02:21 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/15 16:01:09 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		is_bin(char c)
{
	if (c == '0')
			return (0);
	else
			return (1);
}

int		ft_bin_to_dec(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res *= 2;
		res = res + is_bin(str[i]);
		i++;
	}
	return (res);
}

void		ft_dec_to_bin(char c, int pid)
{
	int		i;
	char	base;
	char	res;
	
	i = 0;
	base = 0b00000001;
	while (i < 8)
	{
		res = base & c;
		usleep (600);
		if (res == 0b00000000)
		{
			// write(1, "0\n", 2);
			kill(pid, SIGUSR1);
		}
		else
		{
			// write(1, "1\n", 2);
			kill(pid, SIGUSR2);
		}
		base = base << 1;
		i++;
	}
}