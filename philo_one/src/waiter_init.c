/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/11/09 18:51:45 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

t_waiter			*init_waiter(char **av, long **tab, int i, int ac)
{
	t_waiter *waiter;

	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]);
	waiter->tsleep = ft_atoi(av[4]);
	waiter->nb_eat = tab[2];
	waiter->last_eat = tab[3];
	if (ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	waiter->id = (intptr_t)(i + 1);
	waiter->second = second_fork(waiter);
	waiter->first = first_fork(waiter);
	waiter->j = 0;
	return (waiter);
}
