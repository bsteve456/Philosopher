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
	if (philo_state(waiter) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
		return (1);
	}
//	pthread_mutex_lock(&(waiter->fork[waiter->fn[0]]));
	pthread_mutex_lock(waiter->display);
	has_afork(waiter->id, utime());
	pthread_mutex_unlock(waiter->display);
	return (0);
}

int		lock_fork2(t_waiter *waiter)
{
//	long time;

//	time = utime();
	pthread_mutex_lock(&(waiter->fork[waiter->fn[1]]));
	if (philo_state(waiter) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
		pthread_mutex_unlock(&(waiter->fork[waiter->fn[1]]));
		return (1);
	}
//	pthread_mutex_lock(&(waiter->fork[waiter->fn[1]]));
	pthread_mutex_lock(waiter->display);
	is_eating(waiter->id, utime());
	pthread_mutex_unlock(waiter->display);
	waiter->last_eat[waiter->id - 1] = utime();
	return (0);
}

int		unlock_fork(t_waiter *waiter)
{
	pthread_mutex_unlock(&(waiter->fork[waiter->fn[1]]));
	pthread_mutex_unlock(&(waiter->fork[waiter->fn[0]]));
	waiter->nb_eat[waiter->id - 1] += 1;
	if (waiter->ntoeat != -1 && waiter->nb_eat[waiter->id - 1] == waiter->ntoeat)
		return (1);
	if (philo_state(waiter) == 1)
		return (1);
	pthread_mutex_lock(waiter->display);
	is_sleeping(waiter->id, utime());
	pthread_mutex_unlock(waiter->display);
	return (0);
}
