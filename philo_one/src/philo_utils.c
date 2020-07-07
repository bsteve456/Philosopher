/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:26:27 by blacking          #+#    #+#             */
/*   Updated: 2020/06/19 17:09:56 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


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

void	display_all_msg(t_waiter *waiter, long time)
{
	(void)waiter;
	(void)time;
/*	int i;
//	int display;

	i = 0;
	usleep(500);
	while(i < waiter->nthread)
	{
		display = waiter->display2[i];
	//	usleep(500);
		if (display == 1)
			has_afork(i + 1, time);
		else if (display == 2)
		{
			is_eating(i + 1, time);
			waiter->last_eat[i] = time;
		}
		else if(display == 3)
		{
			has_afork(i + 1, time);
			is_eating(i + 1, time);
			waiter->last_eat[i] = time;
		}
		else if (display == 4)
			is_sleeping(i + 1, time);
		else if (display == 5)
			is_thinking(i + 1, time);
		else if (display == 6)
		{
			is_thinking(i + 1, time);
			has_afork(i + 1, time);
		}
		else if (display == 8)
		{
			is_thinking(i + 1, time);
			has_afork(i + 1, time);
			is_eating(i + 1, time);
		}
		else if (display == 12)
		{
			is_thinking(i + 1, time);
			has_afork(i + 1, time);
			is_eating(i + 1, time);
			is_sleeping(i + 1, time);
		}
		waiter->display2[i] = 0;
		display_msg(i, time, waiter);
		i++;
		if (i < waiter->nthread)
			display_msg(i, time, waiter);
		i++;
	}*/
}

void	dis_utils(long time, int id)
{
	ft_putnbr(time);
	write(1, " ", 2);
	ft_putnbr(id);
}
