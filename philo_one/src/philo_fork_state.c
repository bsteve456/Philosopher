/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/18 19:41:24 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int check_other_philo(t_waiter *waiter)
{
	int i;
	long time;

	i = 0;
	time = utime();
	while (i < waiter->nthread)
	{
		if (time - waiter->last_eat[i] >= waiter->tdie)
			return (i);
		i++;
	}
	return (-1);
}

int	philo_state(t_waiter *waiter)
{
//	int			id;
	static int	ndie = 0;
	long n;

//	id = (intptr_t)(waiter->id);
	if(ndie >= 1)
		return (1);
	n = utime() - waiter->last_eat[waiter->id - 1];
	if(ndie == 0 && n >= waiter->tdie)
	{
		ndie++;
		pthread_mutex_lock(waiter->display);
	//	display2(utime(), id, 5);
		is_dead(waiter->id, utime());
		pthread_mutex_unlock(waiter->display);
		return (1);
	}
	return (0);
}

int	check_state(t_waiter *waiter)
{
	if (philo_state(waiter) == 0)
		return (1);
//	else if (waiter->ntoeat != -1 && waiter->nb_eat[id - 1] == waiter->ntoeat)
//		return (1);
		return (0);
}

/*int	check_die_eat(t_waiter *waiter, int pos)
{
	int id;

	id = (intptr_t)(waiter->id);
	if(check_state(waiter, id) == 1)
	{
//		if(pos == 1)
//		{
//			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[0]]);
//			return (1);
//		}
//		else if (pos == 2)
//		{
			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[1]]);
			pthread_mutex_unlock(&(waiter->fork)[waiter->fn[0]]);
			return (1);
		}
		return (1);
	}
	return (0);
}*/
