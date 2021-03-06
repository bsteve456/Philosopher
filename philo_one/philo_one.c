/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:33:02 by stbaleba          #+#    #+#             */
/*   Updated: 2020/12/14 15:48:11 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				dinner_loop(t_waiter *waiter, pthread_mutex_t *fork)
{
	while (1)
	{
		pthread_mutex_lock(&(fork[waiter->first]));
		pthread_mutex_lock(&(fork[waiter->second]));
		lock_fork(waiter);
		lock_fork2(waiter);
		usleep_eat(waiter);
		pthread_mutex_unlock(&(fork[waiter->second]));
		pthread_mutex_unlock(&(fork[waiter->first]));
		if (*(waiter->end) != 1 && unlock_fork(waiter) == 1)
			break ;
		usleep_sleep(waiter);
		think_msg(waiter);
		if (*(waiter->end) == 1)
			break ;
	}
}

void				*dinner(void *arg)
{
	t_waiter				*waiter;

	waiter = arg;
	think_msg(waiter);
	if (waiter->id % 2 == 0)
		usleep(1000);
	dinner_loop(waiter, waiter->fork);
	return (NULL);
}

void				monitoring_loop(t_waiter *waiter)
{
	t_msg			**tab;
	static	int		i = 0;
	int				*pos;

	if (!(tab = (t_msg **)malloc(sizeof(t_msg *) * waiter->nthread)))
		return ;
	if (!(pos = (int *)malloc(sizeof(int) * waiter->nthread)))
		return ;
	while (i < waiter->nthread)
	{
		tab[i] = waiter->msg[i];
		pos[i++] = 0;
	}
	usleep_ntime(20);
	while (1)
	{
		if (philo_state(waiter) == 1)
			break ;
		mring_dis(tab, &pos, waiter);
		usleep(1000);
	}
	if (*(waiter->end) == 1)
		pending_msg(tab, pos, waiter);
	free(pos);
	free(tab);
}

int					main(int ac, char **av)
{
	t_waiter			*waiter;
	static int			i = 0;
	static pthread_t	*tid = NULL;
	t_info				*info;

	if (!(info = (t_info *)malloc(sizeof(t_info) * 1)))
		return (0);
	if (error_value(av, ac, info) == 1)
	{
		init_pthread_tab(av, info);
		tid = info->tid;
		while (i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, info, i, ac);
			waiter->last_eat[waiter->id - 1] = utime();
			info->moni[i] = waiter;
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			i++;
		}
		monitoring_loop(waiter);
		free_info(info, waiter, tid);
	}
	return (0);
}
