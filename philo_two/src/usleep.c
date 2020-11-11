/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 23:12:34 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

int		error_value(char **av, int ac, t_info *info)
{
	static int i = 1;
	static int n = 1;

	if (ac < 5 || ac > 6)
	{
		write(1, "error: nb of argument should be 5 or 6 args.\n", 47);
		n = 0;
	}
	if (n == 1 && ft_atoi(av[i]) < 2)
	{
		write(1, "Philo nb should be higher than 1.\n", 34);
		n = 0;
	}
	while (n == 1 && i < ac)
	{
		if (!ft_str_is_numeric(av[i]) || ft_atoi(av[i]) < 0)
		{
			write(1, "Error: arg value.\n", 18);
			n = 0;
		}
		i++;
	}
	if (n == 0)
		free(info);
	return (n);
}
