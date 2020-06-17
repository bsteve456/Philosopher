/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/17 03:57:13 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int check_other_philo(t_waiter *waiter)
{
	int i;
	long n;

	i = 0;
	while (i < waiter->nthread)
	{
		n = utime() - waiter->last_eat[i];
//		pthread_mutex_lock(waiter->display);
//		pthread_mutex_unlock(waiter->display);
		if (n >= waiter->tdie)
			return (i);
		i++;
	}
	return (-1);
}

int	philo_state(t_waiter *waiter)
{
	int			id;
	static int	ndie = 0;

	id = (intptr_t)(waiter->id);
	if (check_other_philo(waiter) != -1
		&& (utime() - waiter->last_eat[id - 1])>= waiter->tdie )
	{
		if(ndie == 0)
		{
			pthread_mutex_lock(waiter->display);
			display2(utime(), id, 5);
			pthread_mutex_unlock(waiter->display);
			ndie++;
		}
		return (0);
	}
//	else if (check_other_philo(waiter) == 1)
//		return (0);
	return (1);
}

int	check_state(t_waiter *waiter, int id)
{
	if (philo_state(waiter) == 0)
		return (1);
	else if (waiter->ntoeat != -1 && waiter->nb_eat[id - 1] == waiter->ntoeat)
		return (1);
	else
		return (0);
}

int	check_die_eat(t_waiter *waiter, int pos)
{
	int id;

	id = (intptr_t)(waiter->id);
	if(check_state(waiter, id) == 1)
	{
		if(pos == 1)
		{
			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[0]]);
			return (1);
		}
		else if (pos == 2)
		{
			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[1]]);
			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[0]]);
			return (1);
		}
		return (1);
	}
	return (0);
}
