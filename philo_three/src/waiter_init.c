/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/15 22:22:39 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_waiter	*init_waiter(char **av, int ac)
{
	t_waiter *waiter;

	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]))))
		return (NULL);
	waiter->tdie = ft_atoi(av[2]) * 1000;
	waiter->tdie2 = waiter->tdie;
	waiter->teat = ft_atoi(av[3]) * 1000;
	waiter->tsleep = ft_atoi(av[4]) * 1000;
	waiter->fork = sem_open("/forks", O_CREAT, S_IRWXU, ft_atoi(av[1]));
	waiter->display = sem_open("/display", O_CREAT, S_IRWXU, 1);
	waiter->last_eat = 0;
	if(ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	return (waiter);
}
