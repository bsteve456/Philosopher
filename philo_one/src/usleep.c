/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/10/21 10:54:05 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	usleep_eat(t_waiter *waiter)
{
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat))
		usleep(100);
}

void	usleep_sleep(t_waiter *waiter)
{
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep))
		usleep(100);
}

long	utime()
{
	static struct timeval time;
	static long time_m = 0;

	gettimeofday(&time, NULL);
	time_m = (time.tv_sec * 1000);
	time_m += (time.tv_usec / 1000);
	return (time_m);
}
