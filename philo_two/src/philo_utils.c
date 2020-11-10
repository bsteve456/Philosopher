/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:26:27 by blacking          #+#    #+#             */
/*   Updated: 2020/11/10 14:16:03 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	ft_putnbr(long n)
{
	unsigned long	nb;
	char			c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = -n;
	}
	else
		nb = n;
	c = nb % 10 + '0';
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &c, 1);
}

int		ft_atoi(const char *str)
{
	int	negative;
	int	number;

	number = 0;
	negative = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * negative);
}

void	dis_utils(long time, int id)
{
	ft_putnbr(time);
	write(1, " ", 2);
	ft_putnbr(id);
}
