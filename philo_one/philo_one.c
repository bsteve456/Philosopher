#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;
	int num = 0;

	waiter = arg;
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
	int **tab;
	int i;
	pthread_t *tid;

	i = 0;
	if(ac >= 4)
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
