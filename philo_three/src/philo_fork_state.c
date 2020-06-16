/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 17:33:26 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	p_is_dead(t_waiter *waiter, int id)
{
	long time_m;

	time_m = utime();
	waiter->tdie -= (time_m - waiter->last_eat);
	waiter->last_eat = time_m;
	if (waiter->tdie <= 0)
	{
		ft_display(waiter, 5, id);
		return (1);
	}
	return (0);
}


int		check_state(t_waiter *waiter, int id, int pos)
{
	if(pos == 1)
	{
		if (p_is_dead(waiter, id) == 1)
			return(1);
		ft_display(waiter, 1, id);
		waiter->tdie = waiter->tdie2;
		waiter->ntoeat -= 1;
		return (0);
	}
	else
	{
		sem_post(waiter->fork);
		sem_post(waiter->fork);
		if(p_is_dead(waiter, id) == 1)
			return (1);
		return (0);
	}
}

long	utime()
{
	struct timeval time;
	long time_m;

	gettimeofday(&time, NULL);
	time_m = (time.tv_sec) * 1000 + (time.tv_usec)/1000;
	return (time_m);
}
