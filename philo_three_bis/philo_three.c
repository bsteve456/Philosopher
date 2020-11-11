/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:23:51 by blacking          #+#    #+#             */
/*   Updated: 2020/11/11 17:22:17 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	dinner(int id, t_waiter *waiter)
{
	static int		i = 0;
	pthread_t		*tid;

	if (!(tid = (ft_calloc(sizeof(pthread_t), 1))))
		return ;
	waiter->id = id;
	waiter->last_eat =  utime();
	pthread_create(tid, NULL, &monitor, (void *)(waiter));
	think_msg(waiter);
	if (id % 2 == 0)
		usleep(2000);
	while(1)
	{
		sem_wait(waiter->fork);
		usleep(500);
		sem_wait(waiter->fork);
		lock_fork(waiter);
		lock_fork2(waiter);
		usleep_eat(waiter);
		sem_post(waiter->fork);
		sem_post(waiter->fork);
		if (waiter->end != 1 && unlock_fork(waiter) == 1)
			break ;
		think_msg(waiter);
		usleep_sleep(waiter);
		if (waiter->end == 1)
			break ;
	}
	pthread_join(*tid, NULL);
	free(tid);
	i = waiter->end * 2;
	free(waiter->msg);
	free(waiter);
	exit(i);
}

void	kill_process(t_waiter *waiter, pid_t *pid)
{
	int status;
	int i;

	i = 0;
	while(i < waiter->nthread)
	{
		waitpid(-1, &status, 0);
		if(status == 512)
			break;
		i++;
	}
	i = 0;
	while(i < waiter->nthread)
	{
		kill(pid[i], SIGTERM);
		i++;
	}
	sem_close(waiter->fork);
	sem_close(waiter->display);
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
		waiter->s = utime();
		while (i < ft_atoi(av[1]))
		{
			pid[i] = fork();
			if(pid[i] == 0)
				dinner(i + 1, waiter);
			i++;
		}
		kill_process(waiter, pid);
	}
	return(0);
}
