/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:36:53 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/11 16:37:03 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
