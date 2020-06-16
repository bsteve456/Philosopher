/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:26:27 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 17:31:00 by blacking         ###   ########.fr       */
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

void	ft_display2(t_waiter *waiter, int n, int id)
{
	ft_putnbr(waiter->last_eat);
	write(1, " ", 2);
	ft_putnbr(id);
	if (n == 1)
		ft_putstr(" has taken a fork\n");
	else if (n == 2)
		ft_putstr(" is eating\n");
	else if (n == 3)
		ft_putstr(" is sleeping\n");
	else if(n == 4)
		ft_putstr(" is thinking\n");
	else
		ft_putstr(" died\n");
}

void	ft_display(t_waiter *waiter, int n, int id)
{
	sem_wait(waiter->display);
	usleep(100);
	if (n == 1)
	{
		ft_display2(waiter, 1, id);
		ft_display2(waiter, 1, id);
		ft_display2(waiter, 2, id);
	}
	else if (n == 2)
		ft_display2(waiter, 3, id);
	else if(n == 4)
		ft_display2(waiter, 4, id);
	else
		ft_display2(waiter, 5, id);
	sem_post(waiter->display);
	waiter->tdie += (utime() - waiter->last_eat);
	waiter->last_eat = utime();
}
