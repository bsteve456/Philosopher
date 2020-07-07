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

	if(thread == 1)
		return (ndie);
	i = 0;
	while(i < waiter->nthread)
	{
		n = time - waiter->last_eat[i];
		if (n >= waiter->tdie)
		{
			ndie = 1;
			//pthread_mutex_lock(waiter->display);
			is_dead(i + 1, time);
			//pthread_mutex_unlock(waiter->display);
			return (ndie);
		}
		i++;
	}
	return (0);
}
