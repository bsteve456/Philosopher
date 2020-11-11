/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:30:25 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 17:11:27 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		check_eat(long *time, int *i, t_waiter *waiter)
{
	*time = utime();
	*i = 0;
	while (waiter->ntoeat != -1 &&
	waiter->nb_eat >= waiter->ntoeat && *i < waiter->nthread)
		*i += 1;
	if (*i >= waiter->nthread)
		return (1);
	return (0);
}

int		philo_state(t_waiter *waiter)
{
	static long		n = 0;
	static int		i = 0;
	static long		time1 = 0;

	if (check_eat(&time1, &i, waiter) == 1)
		return (1);
	while (i < waiter->nthread)
	{
		if ((waiter->ntoeat != -1 &&
		waiter->nb_eat < waiter->ntoeat) ||
		waiter->ntoeat == -1)
		{
			n = time1 - waiter->last_eat;
			if (n >= waiter->tdie)
			{
				sem_wait(waiter->display);
//				printf("[%ld]\n", waiter->last_eat - waiter->s);
				waiter->end = 1;
				is_dead(waiter->id, time1 - waiter->s);
				sem_post(waiter->display);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
