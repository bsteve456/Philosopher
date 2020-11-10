/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:46:37 by blacking          #+#    #+#             */
/*   Updated: 2020/11/10 11:50:59 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_eat(long *time, int *i, t_waiter *waiter)
{
	*time = utime();
	*i = 0;
	while (waiter->ntoeat != -1 &&
	waiter->nb_eat[waiter->id - 1] >= waiter->ntoeat && *i < waiter->nthread)
		*i += 1;
	if (*i >= waiter->nthread)
		return (1);
	return (0);
}

int		philo_state(t_waiter *waiter)
{
	static long		n = 0;
	static int		i = 0;
	static long		time1 = 0;

	if (check_eat(&time1, &i, waiter) == 1)
		return (1);
	while (i < waiter->nthread)
	{
		if ((waiter->ntoeat != -1 &&
		waiter->nb_eat[waiter->id - 1] < waiter->ntoeat) ||
		waiter->ntoeat == -1)
		{
			n = time1 - waiter->last_eat[i];
			if (n >= waiter->tdie)
			{
				waiter->dtime = time1 - waiter->s;
				waiter->pdead = i + 1;
				*(waiter->end) = 1;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	mring_dis(t_msg **tab, int **pos1, t_waiter *waiter)
{
	int	i;
	int	j;
	int *pos;

	i = 0;
	pos = *pos1;
	while (i < waiter->nthread)
	{
		j = pos[i];
		if (tab[i][j].msg != 0 && tab[i][j].time != 0)
		{
			dis_msg(i + 1, tab[i][j].msg, tab[i][j].time - waiter->s);
			pos[i] = j + 1;
		}
		if (pos[i] == RESET)
		{
			free(tab[i]);
			tab[i] = waiter->msg[i];
			pos[i] = 0;
		}
		i++;
	}
	*pos1 = pos;
}

void	pending_msg(t_msg **tab, int *pos, t_waiter *waiter)
{
	int end;

	end = 0;
	while (end < waiter->nthread)
	{
		end = 0;
		pg_msg2(tab, pos, waiter, &end);
	}
	is_dead(waiter->pdead, waiter->dtime, waiter->end);
}
