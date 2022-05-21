/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bin_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:02:21 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/21 14:47:46 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_bin(char c)
{
	if (c == '0')
		return (0);
	else
		return (1);
}

int	ft_bin_to_dec(char *str)
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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	s = str;
}
