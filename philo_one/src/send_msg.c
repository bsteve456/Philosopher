/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:56:23 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/02 14:17:45 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


void				think_msg(t_waiter *waiter)
{
	waiter->msg[waiter->id - 1][waiter->j].msg = 5;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if(waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
		write(1, "ok\n", 4);
	}
}

pthread_mutex_t		*init_fork(int n)
{
	pthread_mutex_t	*f;

	if (!(f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t ) * n)))
			return (NULL);
	return (f);
}
