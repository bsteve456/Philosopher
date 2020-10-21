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
//	printf("\nBEFORE EAT :[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat));
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat))
	{
//		if(waiter->id == 1)
//			printf("[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat));
		usleep(1);
	}
//	printf("\nAFTER EAT :[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat));

}

void	usleep_sleep(t_waiter *waiter)
{
//printf("\nBEFORE SLEEEP:[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep));
	while(utime() < (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep))
	{
	//	if(waiter->id == 1)
	//		printf("[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep));
		usleep(1);
	}
//	printf("\nAFTER SLEEEP:[%d][%ld] [%ld]\n", waiter->id, utime(), (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep));

}
