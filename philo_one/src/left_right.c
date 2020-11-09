/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:04:04 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/09 16:24:52 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		first_fork(t_waiter *waiter)
{
	return (waiter->id - 1);
}

int		second_fork(t_waiter *waiter)
{
	return (waiter->id % waiter->nthread);
}

void	pg_msg2(t_msg **tab, int *pos, t_waiter *waiter, int *end)
{
	int i;
	int j;

	i = 0;
	while (i < waiter->nthread)
	{
		j = pos[i];
		if (tab[i][j].msg != 0 && tab[i][j].time != 0 &&
			tab[i][j].time - waiter->s < waiter->dtime)
		{
			dis_msg(i + 1, tab[i][j].msg, tab[i][j].time - waiter->s);
			pos[i] = j + 1;
		}
		else
			*end += 1;
		if (pos[i] == RESET)
		{
			free(tab[i]);
			tab[i] = waiter->msg[i];
			pos[i] = 0;
		}
		i++;
	}
}
