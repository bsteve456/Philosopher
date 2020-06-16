/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:26:27 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 19:38:38 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"


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

void	display2(long time, int id, int n)
{
	ft_putnbr(time);
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
		ft_putstr(" is died\n");

}

void	ft_display(t_waiter *waiter, int n)
{
	int		id;
	long 	last_eat;
//	int 	teat;
//	int 	tsleep;

	usleep(100);
	if(check_other_philo(waiter) == 1)
		return;
	sem_wait(waiter->display);
	id = waiter->id;
//	id = (intptr_t)(waiter->id);
//	last_eat = waiter->last_eat[id - 1];
//	teat = waiter->teat;
//	tsleep = waiter->tsleep;
	last_eat = waiter->last_eat[id - 1];
	if (n == 1)
		display2(last_eat, id, 1);
	else if (n == 2)
	{
		display2(last_eat, id, 1);
		display2(last_eat, id, 2);
	}
	else if (n == 3)
		display2(last_eat, id, 3);
	else if (n == 4)
		display2(last_eat, id, 4);
	waiter->tdie2[id - 1] += (utime() - last_eat);
	waiter->last_eat[id - 1] = utime();
	sem_post(waiter->display);
}
