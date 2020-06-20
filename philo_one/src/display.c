/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:25:54 by blacking          #+#    #+#             */
/*   Updated: 2020/06/18 19:54:37 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	has_afork(int id, long time)
{
	dis_utils(time, id);
	ft_putstr(" has taken a fork\n");
}

void	is_eating(int id, long time)
{
	dis_utils(time, id);
	ft_putstr(" has taken a fork\n");
	dis_utils(time, id);
	ft_putstr(" is eating\n");
}

void	is_sleeping(int id, long time)
{
	dis_utils(time, id);
	ft_putstr(" is sleeping\n");
}

void	is_thinking(int id, long time)
{
	dis_utils(time, id);
	ft_putstr(" is thinking\n");
}

void	is_dead(int id, long time)
{
	dis_utils(time, id);
	ft_putstr(" is died\n");
}

void	test(int id, long time)
{
	ft_putstr("test : ");
	dis_utils(time, id);
	write(1, "\n", 2);
}
