/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_lock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:40:00 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 23:32:28 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	think_msg(t_waiter *waiter)
{
	waiter->msg[waiter->j].msg = 5;
	waiter->msg[waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg = fill_msg();
		waiter->j = 0;
	}
}

int		lock_fork(t_waiter *waiter)
{
	waiter->msg[waiter->j].msg = 1;
	waiter->msg[waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg = fill_msg();
		waiter->j = 0;
	}
	return (0);
}

int		lock_fork2(t_waiter *waiter)
{
	waiter->msg[waiter->j].msg = 2;
	waiter->msg[waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg = fill_msg();
		waiter->j = 0;
	}
	return (0);
}

int		unlock_fork(t_waiter *waiter)
{
	static long time = 0;

	time = utime();
	waiter->last_eat = time;
	waiter->nb_eat += 1;
	if (waiter->ntoeat != -1 &&
	waiter->nb_eat == waiter->ntoeat)
		return (1);
	waiter->msg[waiter->j].msg = 4;
	waiter->msg[waiter->j].time = time;
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg = fill_msg();
		waiter->j = 0;
	}
	return (0);
}
