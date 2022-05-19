/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:00:57 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/18 16:10:31 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	base;
	int	sign;

	i = 0;
	sign = 1;
	base = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v'))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	return (base * sign);
}

void	ft_putnbr(int n)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr((num / 10));
		ft_putnbr((num % 10));
	}
	if (num <= 9)
	{
		ft_putchar(num + '0');
	}
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen((char *)s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (len)
	{
		len--;
		ptr[len] = s1[len];
	}
	return (ptr);
}
