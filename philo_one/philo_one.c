#include "philo_one.h"

int	fork_lock_unlock(t_waiter *waiter, int pos, int lock, int time)
{
	int fn;

	if(lock == 1 && pos == 1)
	{
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		return (check_die_eat(waiter, time, 1, 1));
	}
	else if(lock == 1 && pos == 2)
	{
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_lock(&(waiter->fork[fn]));
		return (check_die_eat(waiter, time, 2, 1));
	}
	else if(lock == 0)
	{
		waiter->tdie2[waiter->id - 1] = waiter->tdie;
		waiter->nb_eat[waiter->id - 1] += 1;
		fn = fork_number(waiter->id, 1, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		fn = fork_number(waiter->id, 2, waiter->nthread);
		pthread_mutex_unlock(&(waiter->fork[fn]));
		return (0);
	}
	return (0);
}

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static int time = 0;

	waiter = arg;
	ft_display(waiter, 4, 0);
	while(1)
	{
		if(fork_lock_unlock(waiter, 1, 1, time) == 1)
			break;
		ft_display(waiter, 1, time);
		if(fork_lock_unlock(waiter, 2, 1, time))
			break;
		waiter->last_eat[waiter->id - 1] = time;
		ft_display(waiter, 2, time);
		fork_lock_unlock(waiter, 0, 0, time);
		time += (waiter->last_eat[waiter->id - 1] + waiter->teat - time);
		if(check_die_eat(waiter, time, 0, waiter->teat) == 1)
			break;
		ft_display(waiter, 3, time);
		time += (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep - time);
		if(check_die_eat(waiter, time, 0, waiter->tsleep) == 1)
			break;
		ft_display(waiter, 4, time);
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
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
		tab = init_tab(av);
		while(i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			pthread_create(&tid[i++], NULL, &dinner, (void *)(waiter));
		}
		i = 0;
		while(i < ft_atoi(av[1]))
			pthread_join(tid[i++], NULL);
	}
	return (0);
}
