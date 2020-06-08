#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;
	int fn;


	waiter = arg;
	printf("%d %d is thinking\n", 0, waiter->id);
	while(1)
	{
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		waiter->tdie2[waiter->id - 1] -= (time - waiter->last_eat[waiter->id - 1]);
		usleep(1000);
		if(ft_check_die_eat(waiter, time, 1) == 1)
			break;
	//	usleep(100);
		printf("%d %d has taken a fork\n", time, waiter->id);
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		waiter->tdie2[waiter->id - 1] -= (time - waiter->last_eat[waiter->id - 1]);
		usleep(1000);
		if(ft_check_die_eat(waiter, time, 2) == 1)
			break;
		printf("%d %d has taken a fork\n", time, waiter->id);
		waiter->last_eat[waiter->id - 1] = time;
		printf("%d %d is eating\n", waiter->last_eat[waiter->id - 1], waiter->id);
	//	usleep(100);
		waiter->tdie2[waiter->id - 1] = waiter->tdie;
		waiter->nb_eat[waiter->id - 1] += 1;
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		time += (waiter->last_eat[waiter->id - 1] + waiter->teat - time);
		waiter->tdie2[waiter->id - 1] -= (time - waiter->last_eat[waiter->id - 1]);
		usleep(waiter->teat * 1000);
		if(ft_check_die_eat(waiter, time, 0) == 1)
			break;
		printf("%d %d is sleeping\n", waiter->last_eat[waiter->id - 1] + waiter->teat, waiter->id);
	//	usleep(100);
		time += (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep - time);
		waiter->tdie2[waiter->id - 1] -= (time - waiter->last_eat[waiter->id - 1]);
		usleep(waiter->tsleep  * 1000);
		if(ft_check_die_eat(waiter, time, 0) == 1)
			break;
		printf("%d %d is thinking\n",waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep, waiter->id);

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
