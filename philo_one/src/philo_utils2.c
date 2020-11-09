/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:45 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/09 15:53:47 by stbaleba         ###   ########.fr       */
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

void	init_pthread_tab(char **av, t_info *info)
{
	int			i;
	pthread_t	*td;
	t_msg		**tab2;

	i = 0;
	if (!(td = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
		return ;
	if (!(tab2 = (t_msg **)malloc(sizeof(t_msg *) * ft_atoi(av[1]))))
		return ;
	if (!(info->end = (int *)malloc(sizeof(int) * 1)))
		return ;
	while (i < ft_atoi(av[1]))
		tab2[i++] = fill_msg();
	info->tid = td;
	info->tab2 = tab2;
	info->start = utime();
	info->tab = init_tab(av);
	*(info->end) = 0;
}
