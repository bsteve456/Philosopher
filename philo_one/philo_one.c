#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;

	waiter = arg;
	waiter->last_eat[waiter->id - 1] = utime();
	pthread_mutex_lock(waiter->display);
	is_thinking(waiter->id, waiter->last_eat[waiter->id - 1]);
	pthread_mutex_unlock(waiter->display);
	while(1)
	{
		if(lock_fork(waiter) == 1)
			break;
		if(lock_fork2(waiter) == 1)
			break;
		usleep(waiter->teat);
		if(unlock_fork(waiter) == 1)
			break;
		usleep(waiter->tsleep);
		if(philo_state(waiter) == 1)
			break;
		pthread_mutex_lock(waiter->display);
		is_thinking(waiter->id, utime());
		pthread_mutex_unlock(waiter->display);
	}
	return (NULL);
}

pthread_mutex_t **init_mutex_tab(char **av)
{
	pthread_mutex_t	**res;

	if (!(res = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * 2)))
		return (NULL);
	res[0] = init_mutex(ft_atoi(av[1]));
	res[1] = init_mutex(1);
	return (res);
}

int main(int ac, char **av)
{
	t_waiter	*waiter;
	long		**tab;
	int			i;
	pthread_t	*tid;
	pthread_mutex_t **mutex;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
		tab = init_tab(av);
		mutex = init_mutex_tab(av);
		while(i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->fork = mutex[0];
			waiter->display = mutex[1];
			pthread_create(&tid[i++], NULL, &dinner, (void *)(waiter));
		}
		i = 0;
		while(i < ft_atoi(av[1]))
			pthread_join(tid[i++], NULL);
	}
	return (0);
}
