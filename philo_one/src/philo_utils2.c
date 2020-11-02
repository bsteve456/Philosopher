/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:45 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/02 15:26:51 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	dis_msg(int id, int msg, long time)
{
	if (msg == 1)
		has_afork(id, time);
	else if (msg == 2)
		is_eating(id, time);
	else if (msg == 4)
		is_sleeping(id, time);
	else if (msg == 5)
		is_thinking(id, time);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *data;

	if (!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
	memset((void *)data, 0, size * count);
	return (data);
}

t_msg	*fill_msg(void)
{
	t_msg	*res;
	int		i;

	if (!(res = (t_msg *)malloc(sizeof(t_msg) * RESET)))
		return (0);
	i = 0;
	while (i < RESET)
	{
		res[i].msg = 0;
		res[i].time = 0;
		i++;
	}
	return (res);
}

void	init_pthread_tab(pthread_t **tid, t_msg ***tab, char *av)
{
	int			i;
	pthread_t	*td;
	t_msg		**tab2;

	i = 0;
	if (!(td = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av) + 1)))
		return ;
	if (!(tab2 = (t_msg **)malloc(sizeof(t_msg *) * ft_atoi(av))))
		return ;
	while (i < ft_atoi(av))
		tab2[i++] = fill_msg();
	*tid = td;
	*tab = tab2;
}
