#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;
	static pthread_mutex_t mutex_time = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t mutex_fork = PTHREAD_MUTEX_INITIALIZER;
	int id = 0;

	waiter = arg;
//	waiter->tdie2[(intptr_t)waiter->id] = (intptr_t)waiter->id;
//	usleep(10);
/*	while(num < waiter->nthread)
	{
		printf("--Philosophe[%ld]--\n", (intptr_t)waiter->id);
		printf("fork[%d] status [%d]\n", num, waiter->fork[num]);
		printf("philosophe[%d] tdie [%d]\n",num, waiter->tdie2[num]);
		printf("philosophe[%d] nb_eat[%d]\n",num, waiter->nb_eat[num]);
		num++;
	}*/
	id = (intptr_t)(waiter->id);
//	static pthread_mutex_t mutex_dinner = PTHREAD_MUTEX_INITIALIZER;
//	printf("%d  philosopher : %d is thinking\n", time, id);
	while(1)
	{
/*		pthread_mutex_lock (&mutex_time);
		time++;
		pthread_mutex_unlock (&mutex_time);*/
		usleep(100);
		if (check_state(waiter, time) == 1)
			break;
		if(ft_check_fork(waiter) == 1)
		{
			pthread_mutex_lock (&mutex_fork);
			printf("%d  philosopher : %d takes a fork\n", time, id);
			printf("%d  philosopher : %d takes a fork\n", time, id);
			if (id == 1)
			{
				waiter->fork[waiter->nthread - 1] = 0;
				waiter->fork[id - 1] = 0;
			}
			else
			{
				waiter->fork[id - 2] = 0;
				waiter->fork[id - 1] = 0;
			}
			printf("%d  philosopher : %d is eating\n", time, id);
			usleep(waiter->teat);
			if (id == 1)
			{
				waiter->fork[waiter->nthread] = 1;
				waiter->fork[id - 1] = 1;
			}
			else
			{
				waiter->fork[id - 2] = 1;
				waiter->fork[id - 1] = 1;
			}
			pthread_mutex_unlock (&mutex_fork);
			waiter->tdie2[id - 1] = waiter->tdie + 1;
			waiter->nb_eat += 1;
			if (check_state(waiter, time) == 1)
				break;
			printf("%d  philosopher : %d is sleeping\n", time, id);
			usleep(waiter->tsleep);
			if (check_state(waiter, time) == 1)
				break;
			printf("%d  philosopher : %d is thinking\n", time, id);
		}
			waiter->tdie2[id - 1] -= 1;
			usleep(100);
			if (check_state(waiter, time) == 1)
				break;
			pthread_mutex_lock (&mutex_time);
			time++;
			pthread_mutex_unlock (&mutex_time);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_waiter *waiter;
	int **tab;
	int i;
	pthread_t *tid;

	i = 0;
	if(ac >= 5)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * atoi(av[1]) + 1)))
			return (0);
		tab = init_tab(av);
		while(i < atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			i++;
		}
		i = 0;
		while(i < atoi(av[1]))
		{
			pthread_join(tid[i], NULL);
			i++;
		}
	}
	return (0);
}
