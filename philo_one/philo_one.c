#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;
	int num = 0;

//	void(arg);
	waiter = arg;
//	(void)waiter;
//	num = (intptr_t)arg;
	num = (intptr_t)(waiter->id);
	static pthread_mutex_t mutex_dinner = PTHREAD_MUTEX_INITIALIZER;

//	num++;
	while(1)
	{
	//	printf("%d  philosopher : %d is thinking\n", time, num);
		pthread_mutex_lock (&mutex_dinner);
		printf("%d  philosopher : %d is thinking\n", time, num);
		time++;
		pthread_mutex_unlock (&mutex_dinner);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_waiter *waiter;
	int i;
	pthread_t *tid;

	i = 0;
	(void)ac;
/*	waiter.nthread = atoi(av[1]);
	waiter.tdie = atoi(av[2]);
	waiter.teat = atoi(av[3]);
	waiter.pnum = 0; */
	if(!(tid = (pthread_t *)malloc(sizeof(pthread_t) * atoi(av[1]) + 1)))
		return (0);
	while(i < atoi(av[1]))
	{
		if(!(waiter = (t_waiter *)malloc(sizeof(t_waiter) * atoi(av[1]) + 1)))
			return (0);
		waiter->nthread = atoi(av[1]);
		waiter->tdie = atoi(av[2]);
		waiter->teat = atoi(av[3]);
		waiter->id = (void *)(intptr_t) i;
//		pthread_create(&tid[i], NULL, &dinner, (void *)(intptr_t) i);
		pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
		i++;
	}
	i = 0;
	while(i < atoi(av[1]))
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}
