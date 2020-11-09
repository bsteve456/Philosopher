/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:56:23 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/09 18:28:53 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				think_msg(t_waiter *waiter)
{
	waiter->msg[waiter->id - 1][waiter->j].msg = 5;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if (waiter->j == RESET)
	{
		waiter->msg[waiter->id - 1] = fill_msg();
		waiter->j = 0;
	}
}

pthread_mutex_t		*init_fork(int n)
{
	pthread_mutex_t	*f;

	if (!(f = ft_calloc(sizeof(pthread_mutex_t), n)))
		return (NULL);
	return (f);
}
