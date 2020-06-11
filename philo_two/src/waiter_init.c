/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:23:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/11 18:01:03 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

sem_t		*init_sem(int n, char *str)
{
	sem_t *res;

	if (n == 1 && *(str + 1) == 'f')
		n++;
	res = sem_open(str, O_CREAT, S_IRWXU, n);
//	sem_unlink(str);
//	res = sem_open(str, O_CREAT, S_IRWXU, n);
	return (res);
}


int			**init_tab(char **av)
{
	int **res;

	if (!(res = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	res[1] = ft_tdie(ft_atoi(av[1]), ft_atoi(av[2]));
	res[2] = ft_nb_eat(ft_atoi(av[1]));
	res[3] = ft_last_eat(ft_atoi(av[1]));
	return (res);
}

t_waiter	*init_waiter(char **av, int **tab, int i, int ac)
{
	t_waiter *waiter;
//	sem_t *fork;
//	sem_t *display;

//	fork = init_sem(ft_atoi(av[1]), "/forks");
//	display = init_sem(1, "/display");
	if (!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * ft_atoi(av[1]) + 1)))
		return (0);
	waiter->nthread = ft_atoi(av[1]);
	waiter->tdie = ft_atoi(av[2]);
	waiter->teat = ft_atoi(av[3]);
	waiter->tsleep = ft_atoi(av[4]);
	waiter->tdie2 = tab[1];
	waiter->nb_eat = tab[2];
	waiter->last_eat = tab[3];
//	waiter->fork = fork;
//	waiter->display = display;
	if(ac == 6)
		waiter->ntoeat = ft_atoi(av[5]);
	else
		waiter->ntoeat = -1;
	waiter->id = (intptr_t)(i + 1);
	return (waiter);
}