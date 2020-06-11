/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:17:12 by blacking          #+#    #+#             */
/*   Updated: 2020/06/11 16:08:24 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int *ft_tdie(int nthread, int tdie)
{
	int *tdie1;
	int i;

	if (!(tdie1 = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		tdie1[i] = tdie;
		i++;
	}
	return (tdie1);
}

int *ft_nb_eat(int nthread)
{
	int *nb_eat;
	int i;

	if (!(nb_eat = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		nb_eat[i] = 0;
		i++;
	}
	return (nb_eat);
}

int *ft_last_eat(int nthread)
{
	int *last_eat;
	int i;

	if (!(last_eat = (int *)malloc(sizeof(int) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		last_eat[i] = 0;
		i++;
	}
	return (last_eat);
}
