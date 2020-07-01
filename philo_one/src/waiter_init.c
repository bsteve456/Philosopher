/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/18 19:44:55 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_mutex_t	*init_mutex(int n)
{
	pthread_mutex_t *res;
	int i;

	i = 0;
	if (n == 1)
		n++;
	if (!(res = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n + 1)))
		return (NULL);
	while (i < n)
	{
		pthread_mutex_init(&res[i], NULL);
		i++;
	}
	return (res);
}

long				**init_tab(char **av)
{
	long **res;

	if (!(res = (long **)malloc(sizeof(long *) * 4)))
		return (0);
	res[2] = ft_nb_eat(ft_atoi(av[1]));
	res[3] = ft_last_eat(ft_atoi(av[1]));
	res[1] = ft_nb_eat(ft_atoi(av[1]));
	return (res);
}

int		*fork_number_init(int id, int nthread)
{
	int *fn;

	if(!(fn = (int *)malloc(sizeof(int) * 2)))
		return (0);
	fn[0] = fork_number(id, 1, nthread);
	fn[1] = fork_number(id, 2, nthread);
	return (fn);
}

t_waiter		*init_waiter(char **av, long **tab, int i, int ac)
{
	t_waiter *waiter;

	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]) * 1000;
	waiter->tsleep = ft_atoi(av[4]) * 1000;
	waiter->display2 = tab[1];
	waiter->nb_eat = tab[2];
	waiter->last_eat = tab[3];
	waiter->fn = fork_number_init(i + 1, waiter->nthread);
	if(ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	waiter->id = (intptr_t)(i + 1);
	return (waiter);
}

long	utime()
{
//	static pthread_mutex_t res = PTHREAD_MUTEX_INITIALIZER;
	static struct timeval time;
	static long time_m = 0;

//	pthread_mutex_lock(&res);
	gettimeofday(&time, NULL);
	time_m = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
//pthread_mutex_unlock(&res);
	return (time_m);
}

