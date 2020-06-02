#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;
//	int *fork = 0;
//	int *tdie = 0;
//	int *nb_eat = 0;
	int num = 0;
	waiter = arg;
//	fork = ft_fork(waiter);
//	tdie = ft_tdie(waiter);
//	nb_eat = ft_nb_eat(waiter);

	waiter->tdie2[(intptr_t)waiter->id] = (intptr_t)waiter->id;
	usleep(10);
	while(num < waiter->nthread)
	{
		printf("--Philosophe[%ld]--\n", (intptr_t)waiter->id);
		printf("fork[%d] status [%d]\n", num, waiter->fork[num]);
		printf("philosophe[%d] tdie [%d]\n",num, waiter->tdie2[num]);
		printf("philosophe[%d] nb_eat[%d]\n",num, waiter->nb_eat[num]);
		num++;
	}
//	num = (intptr_t)(waiter->id);
	static pthread_mutex_t mutex_dinner = PTHREAD_MUTEX_INITIALIZER;
	while(1)
	{
		pthread_mutex_lock (&mutex_dinner);
//		printf("%d  philosopher : %d is thinking\n", time, num);
		time++;
		pthread_mutex_unlock (&mutex_dinner);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_waiter *waiter;
	int *fork;
	int *nb_eat;
	int *tdie;
	int i;
	pthread_t *tid;

	i = 0;
	if(ac >= 4)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * atoi(av[1]) + 1)))
			return (0);
		fork = ft_fork(atoi(av[1]));
		tdie = ft_tdie(atoi(av[1]), atoi(av[2]));
		nb_eat = ft_nb_eat(atoi(av[1]));
		while(i < atoi(av[1]))
		{
			if(!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * atoi(av[1]) + 1)))
				return (0);
			waiter->nthread = atoi(av[1]);
			waiter->tdie = atoi(av[2]);
			waiter->teat = atoi(av[3]);
			waiter->fork = fork;
			waiter->tdie2 = tdie;
			waiter->nb_eat = nb_eat;
			if(ac == 5)
				waiter->ntoeat = atoi(av[4]);
			else
				waiter->ntoeat = -1;
			waiter->id = (void *)(intptr_t) i;
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
