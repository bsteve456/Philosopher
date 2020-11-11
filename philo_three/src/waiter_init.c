/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/11/11 21:42:03 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_msg	*fill_msg(void)
{
	t_msg	*res;
	int		i;

	if (!(res = (t_msg *)malloc(sizeof(t_msg) * RESET)))
		return (0);
	i = 0;
	while (i < RESET)
	{
		res[i].msg = 0;
		res[i].time = 0;
		i++;
	}
	return (res);
}

t_waiter	*init_waiter(char **av, int ac)
{
	t_waiter *waiter;

	sem_unlink("/forks");
	sem_unlink("/display");
	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]))))
		return (NULL);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]);
	waiter->tsleep = ft_atoi(av[4]);
	waiter->end = 0;
	waiter->j = 0;
	waiter->i = 0;
	waiter->msg = fill_msg();
	waiter->fork = sem_open("/forks", O_CREAT, S_IRWXU, ft_atoi(av[1]));
	waiter->display = sem_open("/display", O_CREAT, S_IRWXU, 1);
	if(ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	return (waiter);
}
