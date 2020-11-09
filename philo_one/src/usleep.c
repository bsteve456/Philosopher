/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/09 17:44:47 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	usleep_eat(t_waiter *waiter)
{
	usleep(waiter->teat * 1000);
}

void	usleep_sleep(t_waiter *waiter)
{
	usleep(waiter->tsleep * 1000);
}

void	usleep_ntime(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		usleep(100);
		i++;
	}
}

long	utime(void)
{
	static struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

int		error_value(char **av, int ac)
{
	int i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		write(1, "error: nb of argument should be 5 or 6 args.\n", 47);
		return (0);
	}
	if (ft_atoi(av[i]) < 2)
	{
		write(1, "Philo nb should be higher than 1.\n", 34);
		return (0);
	}
	while (i < ac)
	{
		if (!ft_str_is_numeric(av[i]) || ft_atoi(av[i]) < 0)
		{
			write(1, "Error: arg value.\n", 22);
			return (0);
		}
		i++;
	}
	return (1);
}
