/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:19:27 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 23:33:29 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	reset(long *i, t_msg *msg, t_waiter *waiter)
{
	free(msg);
	msg = waiter->msg;
	*i = 0;
	waiter->i = 0;
}

void	*monitor(void *arg)
{
	t_waiter	*waiter;
	t_msg		*msg;
	long		i;

	waiter = arg;
	i = 0;
	msg = waiter->msg;
	while (1)
	{
		if (philo_state(waiter) == 1)
			return (0);
		if (msg[i].msg != 0 && msg[i].time != 0)
		{
			sem_wait(waiter->display);
			dis_msg(waiter->id, msg[i].msg, msg[i].time - waiter->s);
			sem_post(waiter->display);
			i++;
			waiter->i += 1;
		}
		if (i == RESET)
			reset(&i, msg, waiter);
		usleep(1000);
	}
	return (0);
}

void	dis_msg(int id, int msg, long time)
{
	if (msg == 1)
		has_afork(id, time);
	else if (msg == 2)
		is_eating(id, time);
	else if (msg == 4)
		is_sleeping(id, time);
	else if (msg == 5)
		is_thinking(id, time);
}
