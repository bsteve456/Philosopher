/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:23:51 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 17:33:30 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"


void	has_eat_enough(t_waiter *waiter)
{
	if(waiter->ntoeat == 0)
	{
		sem_post(waiter->fork);
		sem_post(waiter->fork);
		exit(0);
	}
}

void	dinner(int id, t_waiter *waiter)
{
	waiter->last_eat =  utime();
	ft_display(waiter, 4, id);
	while(1)
	{
		sem_wait(waiter->fork);
		sem_wait(waiter->fork);
		if(check_state(waiter, id , 1) == 1)
			exit(2);
		has_eat_enough(waiter);
		usleep(waiter->teat * 1000);
		if(check_state(waiter, id , 2) == 1)
			exit(2);
		ft_display(waiter, 2, id);
		usleep(waiter->tsleep * 1000);
		if(p_is_dead(waiter, id) == 1)
			exit(2);
		ft_display(waiter, 4, id);
	}
}

void	kill_process(char **av, pid_t *pid)
{
	int status;
	int i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		waitpid(-1, &status, 0);
		if(status == 512)
			break;
		i++;
	}
	i = 0;
	while(i < ft_atoi(av[1]))
	{
		kill(pid[i], SIGTERM);
		i++;
	}
}

int main(int ac, char **av)
{
	int			i;
	t_waiter	*waiter;
	pid_t		*pid;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if(!(pid = (pid_t *)malloc(sizeof(pid_t) * ft_atoi(av[1]) + 1)))
			return (0);
		waiter = init_waiter(av, ac);
		while (i < ft_atoi(av[1]))
		{
			pid[i] = fork();
			if(pid[i] == 0)
				dinner(i + 1, waiter);
			i++;
		}
		kill_process(av, pid);
	}
	return(0);
}
