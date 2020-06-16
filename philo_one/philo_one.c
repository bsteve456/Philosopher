#include "philo_one.h"

int	fork_lock_unlock(t_waiter *waiter, int pos, int lock)
{
	int fn;

	if(lock == 1 && pos == 1)
	{
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		return (check_die_eat(waiter, 1));
	}
	else if(lock == 1 && pos == 2)
	{
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		return (check_die_eat(waiter, 2));
	}
	else if(lock == 0)
	{
//		waiter->tdie2[waiter->id - 1] = waiter->tdie;
//		waiter->nb_eat[waiter->id - 1] += 1;
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		waiter->tdie2[waiter->id - 1] = waiter->tdie;
		waiter->nb_eat[waiter->id - 1] += 1;
		return (check_die_eat(waiter, 0));
	}
	return (0);
}

void	*dinner(void *arg)
{
	t_waiter *waiter;
//	static int time = 0;

	waiter = arg;
	waiter->last_eat[waiter->id - 1] = utime();
	ft_display(waiter, 4);
	while(1)
	{
		if(fork_lock_unlock(waiter, 1, 1) == 1)
			break;
		ft_display(waiter, 1);
		if(fork_lock_unlock(waiter, 2, 1) == 1)
			break;
		ft_display(waiter, 2);
		usleep(waiter->teat * 1000);
//		time += (waiter->last_eat[waiter->id - 1] + waiter->teat - time);
		if(fork_lock_unlock(waiter, 0, 0) == 1)
			break;
//		if(check_die_eat(waiter, 0) == 1)
//			break;
		ft_display(waiter, 3);
		usleep(waiter->tsleep * 1000);
//		time += (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep - time);
		if(check_die_eat(waiter, 0) == 1)
			break;
		ft_display(waiter, 4);
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
