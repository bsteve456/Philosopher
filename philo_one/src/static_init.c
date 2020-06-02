/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:17:12 by blacking          #+#    #+#             */
/*   Updated: 2020/06/02 16:57:09 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int *ft_fork(int nthread)
{
	int *fork = NULL;
	int i;

	if(!(fork = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while(i < nthread)
	{
		fork[i] = 1;
		i++;
	}
	return (fork);
}

int *ft_tdie(int nthread, int tdie)
{
	int *tdie1 = NULL;
	int i;

	if(!(tdie1 = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while(i < nthread)
	{
		tdie1[i] = tdie;
		i++;
	}
	return (tdie1);
}

int *ft_nb_eat(int nthread)
{
	int *nb_eat = NULL;
	int i;

	if(!(nb_eat = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while(i < nthread)
	{
		nb_eat[i] = 0;
		i++;
	}
	return (nb_eat);
}
