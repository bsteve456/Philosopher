/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:21:39 by stbaleba          #+#    #+#             */
/*   Updated: 2020/10/21 10:54:05 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	usleep_eat(t_waiter *waiter)
{
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat))
	{
//			printf("[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat));
			usleep(50);
	}
}

void	usleep_sleep(t_waiter *waiter)
{
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep))
			usleep(1);
}
