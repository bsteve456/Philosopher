/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:56:23 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/10 11:44:01 by stbaleba         ###   ########.fr       */
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

void				free_all(t_waiter *waiter, t_waiter **moni)
{
	int i;
	int n;

	n = waiter->nthread;
	i = 0;
	free(waiter->nb_eat);
	free(waiter->last_eat);
	free(waiter->fork);
	free(waiter->tab);
	while (i < n)
	{
		free(waiter->msg[i]);
		i++;
	}
	free(waiter->msg);
	free(waiter->end);
	i = 0;
	while (i < n)
	{
		free(moni[i]);
		i++;
	}
	free(moni);
}

void				free_info(t_info *info, t_waiter *waiter, pthread_t *tid)
{
	int i;

	i = 0;
	while (i < waiter->nthread)
		pthread_join(tid[i++], NULL);
	free_all(waiter, info->moni);
	free(tid);
	free(info);
}
