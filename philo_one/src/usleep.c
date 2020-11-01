/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/10/26 14:15:10 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	usleep_eat(t_waiter *waiter)
{
//	static struct timespec req;
//	(void)waiter;
//	req.tv_sec = 0;
//	req.tv_nsec = 200000000;
//	while (utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat))
//		usleep(50);
//		nanosleep(&req, NULL);
		usleep(waiter->teat * 1000);
}

void	usleep_sleep(t_waiter *waiter)
{
//	static struct timespec req;
//	(void)waiter;
//	req.tv_sec = 0;
//	req.tv_nsec = 200000000;
//	while (utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep))
//		usleep(50);
//		nanosleep(&req, NULL);
		usleep(waiter->tsleep * 1000);

}


void	usleep_ntime(int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		usleep(100);
		i++;
	}
}

long	utime()
{
	static struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}
