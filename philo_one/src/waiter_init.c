/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/04 16:44:12 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		**init_tab(char **av)
{
	int **res;

	if(!(res = (int **)malloc(sizeof(int *) * 3)))
		return (0);
	res[0] = ft_fork(atoi(av[1]));
	res[1] = ft_tdie(atoi(av[1]), atoi(av[2]));
	res[2] = ft_nb_eat(atoi(av[1]));
	return (res);
}

t_waiter *init_waiter(char **av, int **tab, int i, int ac)
{
	t_waiter *waiter;

	if(!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = atoi(av[1]);
	waiter->tdie = atoi(av[2]);
	waiter->teat = atoi(av[3]);
	waiter->tsleep = atoi(av[4]);
	waiter->fork = tab[0];
	waiter->tdie2 = tab[1];
	waiter->nb_eat = tab[2];
	if(ac == 6)
		waiter->ntoeat = atoi(av[5]);
	else
		waiter->ntoeat = -1;
	waiter->id = (void *)(intptr_t)(i + 1);
	return (waiter);
}
