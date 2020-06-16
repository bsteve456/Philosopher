/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/17 01:18:12 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int check_other_philo(t_waiter *waiter)
{
	int i;

	i = 0;
	while (i < waiter->nthread)
	{
		if (waiter->tdie2[i] <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	philo_state(t_waiter *waiter)
{
	int			id;
	static int	ndie = 0;

	id = (intptr_t)(waiter->id);
	if (waiter->tdie2[id - 1] <= 0 && ndie == 0)
	{
		ndie++;
		pthread_mutex_lock(waiter->display);
		display2(waiter->last_eat[id - 1], id, 5);
		pthread_mutex_unlock(waiter->display);
		return (0);
	}
	else if (check_other_philo(waiter) == 1)
		return (0);
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
	long time_m;

	id = (intptr_t)(waiter->id);
	time_m = utime();
	waiter->tdie2[id - 1] -= (time_m - waiter->last_eat[id - 1]);
	waiter->last_eat[waiter->id - 1] = time_m;
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
