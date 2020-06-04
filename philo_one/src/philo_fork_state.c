/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/04 17:21:54 by blacking         ###   ########.fr       */
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
		if (waiter->nb_eat[i] != waiter->ntoeat)
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
		printf("%d philosopher : %d died\n", time, id);
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

int	ft_check_fork(t_waiter *waiter)
{
	int id;
	int last_id;

	id = (intptr_t)(waiter->id);
	last_id = waiter->nthread;
	if (id == 1 && (waiter->fork[last_id - 1] == 1 &&
		waiter->fork[id - 1] == 1))
	{
//		printf("yes\n");
		return (1);
	}
	else if (id != 1 && waiter->fork[id - 2] == 1 && waiter->fork[id - 1] == 1)
		return (1);
//	printf("no\n");
	return (0);
}
