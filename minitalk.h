/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:51:46 by aadnane           #+#    #+#             */
/*   Updated: 2022/05/14 18:33:42 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		is_bin(char c);
int		ft_bin_to_dec(char *str);
void	ft_putstr(char *str);
void	ft_dec_to_bin(char c, int pid);
char	*ft_strdup(const char *s1);


#endif