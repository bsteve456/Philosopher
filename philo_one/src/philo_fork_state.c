/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/12 17:26:28 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


int nb_eat(t_waiter *waiter)
{
	int i;

	i = 0;
	if (waiter->ntoeat < 0)
		return (0);
	while (i < waiter->nthread)
	{
		if (waiter->nb_eat[i] < waiter->ntoeat)
			return (0);
		i++;
	}
	return (1);
}

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

int	philo_state(t_waiter *waiter, int time)
{
	int id;

	id = (intptr_t)(waiter->id);
	if (waiter->tdie2[id - 1] <= 0)
	{
		printf("%d %d died\n", time, id);
		return (0);
	}
	else if (check_other_philo(waiter) == 1)
		return (0);
	return (1);
}

int	check_state(t_waiter *waiter, int time)
{
	if (philo_state(waiter, time) == 0 ||
		nb_eat(waiter) == 1)
		return (1);
	else
		return (0);
}

int	check_die_eat(t_waiter *waiter, int time, int pos, int slep)
{
	int id;
	int last_id;
	int fork_n;

	id = (intptr_t)(waiter->id);
	usleep(slep * 1000);
	if(pos != 0)
	{
		waiter->tdie2[id - 1] -= (time - waiter->last_eat[id - 1]);
		waiter->last_eat[waiter->id - 1] = time;
	}
	else
		waiter->tdie2[id - 1] -= slep;
	usleep(slep * 1000);
	last_id = waiter->nthread;
	fork_n = fork_number(id, pos, last_id);
	if (pos == 1 && check_state(waiter, time) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork)[fork_n]);
		return (1);
	}
	else if (pos == 2 && check_state(waiter, time) == 1)
	{
		pthread_mutex_unlock(&(waiter->fork)[fork_n]);
		fork_n = fork_number(id, 1, last_id);
		pthread_mutex_unlock(&(waiter->fork)[fork_n]);
		return (1);
	}
	else if (check_state(waiter, time) == 1)
		return (1);
	return (0);
}
