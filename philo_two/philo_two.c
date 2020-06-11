#include "philo_two.h"

int	fork_lock_unlock(t_waiter *waiter, int pos, int lock, int time)
{
	if(lock == 1 && pos == 2)
	{
		sem_wait(waiter->fork);
		sem_wait(waiter->fork);
		return (check_die_eat(waiter, time, 2, 1));
	}
	else if(lock == 0)
	{
		waiter->tdie2[waiter->id - 1] = waiter->tdie;
		sem_post(waiter->fork);
		sem_post(waiter->fork);
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
		usleep(1000 * (waiter->id));
		if(fork_lock_unlock(waiter, 2, 1, time) == 1)
			break;
		waiter->last_eat[waiter->id - 1] = time;
		ft_display(waiter, 1, time);
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
	sem_t *display;
	sem_t *fork;
	pthread_t *tid;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		sem_unlink("/display");
		sem_unlink("/forks");
		display = init_sem(1, "/display");
		fork = init_sem(ft_atoi(av[1]), "/forks");
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
		tab = init_tab(av);
		while(i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->display = display;
			waiter->fork = fork;
			pthread_create(&tid[i++], NULL, &dinner, (void *)(waiter));
		}
		i = 0;
		while(i < ft_atoi(av[1]))
			pthread_join(tid[i++], NULL);
	}
	return (0);
}
