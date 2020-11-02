/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:33:02 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/02 14:25:42 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				dinner_loop(t_waiter *waiter, pthread_mutex_t *fork)
{
	while (1)
	{
		pthread_mutex_lock(&(fork[left(waiter->id, waiter->nthread)]));
		lock_fork(waiter);
		pthread_mutex_lock(&(fork[waiter->id - 1]));
		lock_fork2(waiter);
		usleep_eat(waiter);
		pthread_mutex_unlock(&(fork[waiter->id - 1]));
		pthread_mutex_unlock(&(fork[left(waiter->id, waiter->nthread)]));
		if (unlock_fork(waiter) == 1)
			break ;
		usleep_sleep(waiter);
		think_msg(waiter);
		if (philo_state(waiter, 1) == 1)
			break ;
	}
}

void				*dinner(void *arg)
{
	t_waiter				*waiter;
	static pthread_mutex_t	*fork = 0;

	waiter = arg;
	if (fork == 0 && waiter->id - 1 == 0)
	{
		if (!(fork = init_fork(waiter->nthread)))
			return (NULL);
	}
	else
		usleep(1000);
	think_msg(waiter);
	if ((waiter->id) % 2 == 0)
		usleep(1000);
	dinner_loop(waiter, fork);
	return (NULL);
}

pthread_mutex_t		**init_mutex_tab(char **av)
{
	pthread_mutex_t	**res;

	if (!(res = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * 2)))
		return (NULL);
	res[0] = init_mutex(ft_atoi(av[1]));
	res[1] = init_mutex(1);
	return (res);
}

void				monitoring_loop(t_waiter *waiter)
{
	t_msg	**tab;
	int		i;
	int		pos[waiter->nthread];

	if (!(tab = (t_msg **)malloc(sizeof(t_msg *) * waiter->nthread)))
		return ;
	i = 0;
	while (i < waiter->nthread)
	{
		tab[i] = waiter->msg[i];
		pos[i] = 0;
		i++;
	}
	usleep_ntime(20);
	while (1)
	{
		if (philo_state(waiter, 0) == 1)
			return ;
		mring_dis(tab, pos, waiter);
		usleep(1000);
	}
}

int					main(int ac, char **av)
{
	t_waiter		*waiter;
	long			**tab;
	static int		i = 0;
	pthread_t		*tid;
	t_msg			**tab2;

	tid = NULL;
	tab2 = NULL;
	if (ac >= 5 && ft_atoi(av[1]) > 0)
	{
		init_pthread_tab(&tid, &tab2, av[1]);
		tab = init_tab(av);
		while (i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->last_eat[waiter->id - 1] = utime();
			waiter->msg = tab2;
			waiter->j = 0;
			waiter->s = utime();
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			pthread_detach(tid[i++]);
		}
		monitoring_loop(waiter);
	}
	return (0);
}
