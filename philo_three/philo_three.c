/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:23:51 by blacking          #+#    #+#             */
/*   Updated: 2020/06/15 22:23:08 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"


void	dinner(int id, t_waiter *waiter)
{
	struct timeval time;
	int time_m;

	gettimeofday(&time, NULL);
	time_m = ((int)(time.tv_usec));
	waiter->last_eat = time_m;
	printf("%d %d is thinking\n", waiter->last_eat, id);
	while(1)
	{
		sem_wait(waiter->fork);
		sem_wait(waiter->fork);
		if(p_is_dead(waiter, id) == 1)
			break;
		printf("%d %d has taken a fork\n", waiter->last_eat, id);
		printf("%d %d has taken a fork\n", waiter->last_eat, id);
		printf("%d %d is eating\n", waiter->last_eat, id);
		waiter->tdie = waiter->tdie2;
		waiter->ntoeat -= 1;
		if(waiter->ntoeat == 0)
		{
			sem_post(waiter->fork);
			sem_post(waiter->fork);
			exit(0);
		}
		usleep(waiter->teat);
		sem_post(waiter->fork);
		sem_post(waiter->fork);
		if(p_is_dead(waiter, id) == 1)
			break;
		printf("%d %d is sleeping\n", waiter->last_eat, id);
		usleep(waiter->tsleep);
		if(p_is_dead(waiter, id) == 1)
			break;
		printf("%d %d is thinking\n", waiter->last_eat, id);
	}
}

int main(int ac, char **av)
{
	int i;
	int status;
	t_waiter *waiter;
	pid_t *pid;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		sem_unlink("/forks");
		sem_unlink("/display");
		if(!(pid = (pid_t *)malloc(sizeof(pid_t) * ft_atoi(av[1]) + 1)))
			return (0);
		waiter = init_waiter(av, ac);
		while (i < atoi(av[1]))
		{
			pid[i] = fork();
			if(pid[i] == 0)
			{
				dinner(i + 1, waiter);
				exit(2);
			}
			i++;
		}
		i = 0;
		while(i < atoi(av[1]))
		{
			waitpid(-1, &status, 0);
			if(status == 512)
				break;
			i++;
		}
		i = 0;
		while(i < atoi(av[1]))
		{
			kill(pid[i], SIGTERM);
			i++;
		}
	}
return(0);
}
