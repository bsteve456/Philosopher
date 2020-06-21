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
	static int	ndie = 0;
	long n;

	if(ndie >= 1)
		return (1);
	n = utime() - waiter->last_eat[waiter->id - 1];
	if(ndie == 0 && n >= waiter->tdie)
	{
		ndie++;
		pthread_mutex_lock(waiter->display);
		is_dead(waiter->id, utime());
		pthread_mutex_unlock(waiter->display);
		return (1);
	}
	return (0);
}
