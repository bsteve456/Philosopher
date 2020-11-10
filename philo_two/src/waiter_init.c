/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/11/10 14:17:41 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long				**init_tab(char **av)
{
	long **res;

	if (!(res = (long **)malloc(sizeof(long *) * 2)))
		return (0);
	res[1] = ft_last_eat(ft_atoi(av[1]));
	res[0] = ft_nb_eat(ft_atoi(av[1]));
	return (res);
}

t_waiter			*init_waiter(char **av, t_info *info, int i, int ac)
{
	t_waiter *waiter;

	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]);
	waiter->tsleep = ft_atoi(av[4]);
	waiter->nb_eat = info->tab[0];
	waiter->tab = info->tab;
	waiter->s = info->start;
	waiter->fork = info->fork;
	waiter->msg = info->tab2;
	waiter->end = info->end;
	waiter->last_eat = info->tab[1];
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
