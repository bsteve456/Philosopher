/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:17:12 by blacking          #+#    #+#             */
/*   Updated: 2020/11/02 12:53:52 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long *ft_tdie(int nthread, long tdie)
{
	long *tdie1;
	int i;

	if (!(tdie1 = (long *)malloc(sizeof(long) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		tdie1[i] = tdie;
		i++;
	}
	return (tdie1);
}

long *ft_nb_eat(int nthread)
{
	long *nb_eat;
	int i;

	if (!(nb_eat = (long *)malloc(sizeof(long) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		nb_eat[i] = 0;
		i++;
	}
	return (nb_eat);
}

long *ft_last_eat(int nthread)
{
	long *last_eat;
	int i;

	if (!(last_eat = (long *)malloc(sizeof(long) * nthread)))
		return (0);
	i = 0;
	while (i < nthread)
	{
		last_eat[i] = 0;
		i++;
	}
	return (last_eat);
}

int	left(int x, int y)
{
	return (x % y);
}
