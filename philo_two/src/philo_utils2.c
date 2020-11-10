/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:45 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/10 14:16:15 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	int			n;

	i = 0;
	n = ft_atoi(av[1]);
	if (!(td = (pthread_t *)malloc(sizeof(pthread_t) * (n + 1))))
		return ;
	if (!(tab2 = (t_msg **)malloc(sizeof(t_msg *) * n)))
		return ;
	if (!(info->end = (int *)malloc(sizeof(int) * 1)))
		return ;
	if (!(info->moni = (t_waiter **)malloc(sizeof(t_waiter *) * n)))
		return ;
	while (i < ft_atoi(av[1]))
		tab2[i++] = fill_msg();
	info->tid = td;
	info->tab2 = tab2;
	info->start = utime();
	info->tab = init_tab(av);
	if (!(info->fork = init_fork(ft_atoi(av[1]))))
		return ;
	*(info->end) = 0;
}

int		ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
