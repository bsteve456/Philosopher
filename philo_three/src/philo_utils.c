/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:36:28 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 16:36:33 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void ft_putnbr(long n)
{
	unsigned long	nb;
	char			c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1 );
		nb = -n;
	}
	else
		nb = n;
	c = nb % 10 + '0';
	if(nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int negative;
	int number;

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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *data;

	if (!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
	memset((void *)data, 0, size * count);
	return (data);
}

void	dis_utils(long time, int id)
{
	ft_putnbr(time);
	write(1, " ", 2);
	ft_putnbr(id);
}

void	dis_msg(int id, int msg, long time)
{
	if (msg == 1)
		has_afork(id, time);
	else if (msg == 2)
		is_eating(id, time);
	else if (msg == 4)
		is_sleeping(id, time);
	else if (msg == 5)
		is_thinking(id, time);
}
