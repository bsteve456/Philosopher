/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/05 21:15:30 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	usleep_eat(t_waiter *waiter)
{
	usleep(waiter->teat * 1000);
}

void	usleep_sleep(t_waiter *waiter)
{
	usleep(waiter->tsleep * 1000);
}

void	usleep_ntime(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		usleep(100);
		i++;
	}
}

long	utime(void)
{
	static struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}
