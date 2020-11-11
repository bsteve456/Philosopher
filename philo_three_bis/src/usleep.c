/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:43:24 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 17:12:30 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_three.h"

void	usleep_eat(t_waiter *waiter)
{
	usleep(waiter->teat * 1000);
}

void	usleep_sleep(t_waiter *waiter)
{
	usleep(waiter->tsleep * 1000);
}

long	utime(void)
{
	static struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

/*int		error_value(char **av, int ac, t_info *info)
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
			write(1, "Error: arg value.\n", 22);
			n = 0;
		}
		i++;
	}
	if (n == 0)
		free(info);
	return (n);
}*/
