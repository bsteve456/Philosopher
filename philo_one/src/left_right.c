/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:04:04 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/03 20:19:05 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		first_fork(t_waiter *waiter)
{
	if (waiter->id % 2)
		return (waiter->id % waiter->nthread);
	else
		return (waiter->id - 1);
}

int		second_fork(t_waiter *waiter)
{
	if (waiter->id % 2)
		return (waiter->id - 1);
	else
		return (waiter->id % waiter->nthread);
}
