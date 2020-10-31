/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_lock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:02:58 by blacking          #+#    #+#             */
/*   Updated: 2020/06/19 17:08:49 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		lock_fork(t_waiter *waiter)
{
//	pthread_mutex_lock(&(waiter->fork[waiter->fn[0]]));
	waiter->msg[waiter->id - 1][waiter->j].msg = 1;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if(waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
		write(1, "ok\n", 4);

	}
	return (0);
}

int		lock_fork2(t_waiter *waiter)
{
	long time;

	time = utime();
//	pthread_mutex_lock(&(waiter->fork[waiter->fn[1]]));
	waiter->msg[waiter->id - 1][waiter->j].msg = 2;
	waiter->msg[waiter->id - 1][waiter->j].time = time;
	waiter->j += 1;
	waiter->last_eat[waiter->id - 1] = time;
	if(waiter->j == RESET)
	{
		waiter->msg[waiter->id] = fill_msg();
		waiter->j = 0;
		write(1, "ok\n", 4);
	}
	return (0);
}

int		unlock_fork(t_waiter *waiter)
{
//	pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
//	pthread_mutex_unlock(&(waiter->fork[waiter->fn[1]]));
	waiter->nb_eat[waiter->id - 1] += 1;
	if (waiter->ntoeat != -1 && waiter->nb_eat[waiter->id - 1] == waiter->ntoeat)
		return (1);
	waiter->msg[waiter->id - 1][waiter->j].msg = 4;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if(waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
		write(1, "ok\n", 4);
	}
	return (0);
}
