/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/10/21 11:52:21 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	philo_state(t_waiter *waiter, int thread, long time)
{
	static int	ndie = 0;
	static	long n = 0;
	static 	int i = 0;
	static	long time1 = 0;

	if(thread == 1)
		return (ndie);
	i = 0;
	time1 = utime();
	while (waiter->ntoeat != -1  &&
	waiter->nb_eat[waiter->id - 1] >= waiter->ntoeat && i < waiter->nthread)
		i++;
	if (i >= waiter->nthread)
		return 1;
	while(i < waiter->nthread)
	{
		if ((waiter->ntoeat != -1  &&
		waiter->nb_eat[waiter->id - 1] >= waiter->ntoeat) || waiter->ntoeat == -1)
		{
			n = time1 - waiter->last_eat[i];
			if (n >= waiter->tdie)
			{
				ndie = 1;
				printf("%ld\n", waiter->last_eat[i] - time);
				is_dead(i + 1, time1 - time);
				return (ndie);
			}
		}
		i++;
	}
	return (0);
}
