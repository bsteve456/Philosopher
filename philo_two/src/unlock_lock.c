/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_lock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:02:58 by blacking          #+#    #+#             */
/*   Updated: 2020/11/10 15:36:32 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		lock_fork(t_waiter *waiter)
{
	waiter->msg[waiter->id - 1][waiter->j].msg = 1;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
	}
	return (0);
}

int		lock_fork2(t_waiter *waiter)
{
	waiter->msg[waiter->id - 1][waiter->j].msg = 2;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg[waiter->id] = fill_msg();
		waiter->j = 0;
	}
	return (0);
}

int		unlock_fork(t_waiter *waiter)
{
	waiter->last_eat[waiter->id - 1] = utime();
	waiter->nb_eat[waiter->id - 1] += 1;
	if (waiter->ntoeat != -1 &&
	waiter->nb_eat[waiter->id - 1] == waiter->ntoeat)
		return (1);
	waiter->msg[waiter->id - 1][waiter->j].msg = 4;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
	}
	return (0);
}
