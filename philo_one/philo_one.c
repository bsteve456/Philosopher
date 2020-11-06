/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:33:02 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/06 16:28:36 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				dinner_loop(t_waiter *waiter, pthread_mutex_t *fork)
{
	while (1)
	{
		pthread_mutex_lock(&(fork[waiter->first]));
//		waiter->fork[waiter->first] = 0;
//		lock_fork(waiter);
		if (waiter->fork[waiter->second] == 0)
		{
			pthread_mutex_unlock(&(fork[waiter->first]));
			waiter->fork[waiter->first] = 1;
		}
		else
		{
			waiter->fork[waiter->first] = 0;
			lock_fork(waiter);
			pthread_mutex_lock(&(fork[waiter->second]));
			waiter->fork[waiter->second] = 0;
			lock_fork2(waiter);
			usleep_eat(waiter);
			pthread_mutex_unlock(&(fork[waiter->second]));
			pthread_mutex_unlock(&(fork[waiter->first]));
			waiter->fork[waiter->second] = 1;
			waiter->fork[waiter->first] = 1;
			if (unlock_fork(waiter) == 1)
				break ;
			usleep_sleep(waiter);
			think_msg(waiter);
			usleep(100);
		}
		if (*(waiter->end) == 1)
			break ;
	}
}

void				*dinner(void *arg)
{
	t_waiter				*waiter;
	static pthread_mutex_t	*fork = 0;
	static int i = 0;

	waiter = arg;
//	if ((waiter->id) % 2 == 0)
//		usleep(100);
	if (i == 0)
	{
		i++;
		if (!(fork = init_fork(waiter->nthread)))
			return (NULL);
	}
	think_msg(waiter);
//	if ((waiter->id) % 2 == 0)
//		usleep(100);
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
	int		*pos;

	if (!(tab = (t_msg **)malloc(sizeof(t_msg *) * waiter->nthread)))
		return ;
	if (!(pos = (int *)malloc(sizeof(int) * waiter->nthread)))
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
		if (philo_state(waiter) == 1)
			break ;
		mring_dis(tab, &pos, waiter);
		usleep(1000);
	}
	pending_msg(tab, pos, waiter);
}

int					main(int ac, char **av)
{
	t_waiter		*waiter;
	long			**tab;
	static int		i = 0;
	pthread_t		*tid;
	t_msg			**tab2;
	int				*fork;
	int			*end;

	tid = NULL;
	tab2 = NULL;
	end = 0;
	fork = 0;
	if (ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if (!(end = (int *)malloc(sizeof(int) * 1)))
			return (0);
		if (!(fork = (int *)malloc(sizeof(int) * ft_atoi(av[1]))))
			return (0);
		*end = 0;
		for(int j = 0; j < ft_atoi(av[1]); j++)
			fork[j] = 1;
		init_pthread_tab(&tid, &tab2, av[1]);
		tab = init_tab(av);
		while (i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->last_eat[waiter->id - 1] = utime();
			waiter->msg = tab2;
			waiter->j = 0;
			waiter->end = end;
			waiter->fork = fork;
			waiter->s = utime();
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			pthread_detach(tid[i++]);
		}
		monitoring_loop(waiter);
	}
	return (0);
}
