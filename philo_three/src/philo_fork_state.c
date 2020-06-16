/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 15:38:40 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	p_is_dead(t_waiter *waiter, int id)
{
	struct timeval time;
	int time_m;

	gettimeofday(&time, NULL);
	time_m = ((int)(time.tv_usec));
	waiter->tdie -= (time_m - waiter->last_eat);
	waiter->last_eat = time_m;
	if (waiter->tdie <= 0)
	{
		sem_wait(waiter->display);
		printf("%d %d died\n", time_m / 1000, id);
		sem_post(waiter->display);
		return (1);
	}
	return (0);
}


int		check_state(t_waiter *waiter, int id, int pos)
{
	if(pos == 1)
	{
		sem_wait(waiter->fork);
		sem_wait(waiter->fork);
		if (p_is_dead(waiter, id) == 1)
			return(1);
		printf("%d %d has taken a fork\n", waiter->last_eat / 1000, id);
		printf("%d %d has taken a fork\n", waiter->last_eat / 1000, id);
		printf("%d %d is eating\n", waiter->last_eat / 1000, id);
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
