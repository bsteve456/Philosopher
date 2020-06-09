/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/09 17:45:30 by blacking         ###   ########.fr       */
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


int				**init_tab(char **av)
{
	int **res;

	if (!(res = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	res[1] = ft_tdie(ft_atoi(av[1]), ft_atoi(av[2]));
	res[2] = ft_nb_eat(ft_atoi(av[1]));
	res[3] = ft_last_eat(ft_atoi(av[1]));
	return (res);
}

t_waiter		*init_waiter(char **av, int **tab, int i, int ac)
{
	t_waiter *waiter;
	pthread_mutex_t *fork;

	fork = init_mutex(ft_atoi(av[1]));
	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]);
	waiter->tsleep = ft_atoi(av[4]);
	waiter->tdie2 = tab[1];
	waiter->nb_eat = tab[2];
	waiter->last_eat = tab[3];
	waiter->fork = fork;
	if(ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	waiter->id = (intptr_t)(i + 1);
	return (waiter);
}
