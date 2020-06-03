/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/06/03 17:06:39 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


int nb_eat(t_waiter *waiter)
{
	int i;

	i = 0;

	if(waiter->ntoeat < 0)
		return (0);
	while(i < waiter->nthread)
	{
		if(waiter->nb_eat[i] != waiter->ntoeat)
			return (0);
		i++;
	}
	return (1);
}

int check_other_philo(t_waiter *waiter)
{
	int i;

	i = 0;
	while(i < waiter->nthread)
	{
		if(waiter->tdie2[i] <= 0)
			return (1);
		i++;
	}
	return (0);
}



int	philo_state(t_waiter *waiter, int time)
{
	int id;

	id = (intptr_t)(waiter->id);
	if(waiter->tdie2[id - 1] <= 0)
	{
		printf("%d : philo [%d] died\n", time, id + 1);
		return (0);
	}
	else if(check_other_philo(waiter) == 1)
		return (0);
	return (1);
}

int	check_state(t_waiter *waiter, int time)
{
	if(check_philo(waiter, time) == 0 ||
		nb_eat(waiter) == 1)
		return (1);
	else
		return (0);

}