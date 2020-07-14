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
	pthread_mutex_lock(&(waiter->fork[waiter->fn[0]]));
/*	if (philo_state(waiter, 1, 0) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
		return (1);
	}*/
/*	pthread_mutex_lock(waiter->display);
	msgadd_back(waiter, msgnew(waiter->id, 1, utime()));
//	waiter->msg = waiter->msg->next;
	pthread_mutex_unlock(waiter->display);*/
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
	pthread_mutex_lock(&(waiter->fork[waiter->fn[1]]));
/*	if (philo_state(waiter, 1, 0) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[1]]));
		return (1);
	}*/
/*	pthread_mutex_lock(waiter->display);
	msgadd_back(waiter, msgnew(waiter->id, 2, utime()));
	waiter->last_eat[waiter->id - 1] = utime();
//	waiter->msg = waiter->msg->next;
	pthread_mutex_unlock(waiter->display);*/
	waiter->msg[waiter->id - 1][waiter->j].msg = 2;
	waiter->msg[waiter->id - 1][waiter->j].time = time;
	waiter->j += 1;
//	pthread_mutex_lock(waiter->display);
	waiter->last_eat[waiter->id - 1] = time;
//	pthread_mutex_unlock(waiter->display);
	if(waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
		write(1, "ok\n", 4);
	}
	return (0);
}

int		unlock_fork(t_waiter *waiter)
{
	pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
	pthread_mutex_unlock(&(waiter->fork[waiter->fn[1]]));
	waiter->nb_eat[waiter->id - 1] += 1;
	if (waiter->ntoeat != -1 && waiter->nb_eat[waiter->id - 1] == waiter->ntoeat)
		return (1);
//	if (philo_state(waiter, 1, 0) == 1)
//		return (1);
/*	pthread_mutex_lock(waiter->display);
	msgadd_back(waiter, msgnew(waiter->id, 4, utime()));
//	waiter->msg = waiter->msg->next;
	pthread_mutex_unlock(waiter->display);*/
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
