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

int	philo_state(t_waiter *waiter, int thread, long time)
{
	static int	ndie = 0;
	static	long n = 0;
	static 	int i = 0;
	static	long time1 = 0;

	(void)time;
	if(thread == 1)
		return (ndie);
	i = 0;
//	pthread_mutex_lock(waiter->display);
	time1 = utime();
//	pthread_mutex_unlock(waiter->display);
	while(i < waiter->nthread)
	{
		n = time1 - waiter->last_eat[i];
		if (n >= waiter->tdie)
		{
			ndie = 1;
			//pthread_mutex_lock(waiter->display);
			printf("%ld\n", waiter->last_eat[i]);
			is_dead(i + 1, time1);
			//pthread_mutex_unlock(waiter->display);
			return (ndie);
		}
		i++;
	}
	return (0);
}
