#include "philo_two.h"

int	fork_lock_unlock(t_waiter *waiter, int lock)
{
	if(lock == 1)
	{
		sem_wait(waiter->fork);
		sem_wait(waiter->fork);
		return (check_die_eat(waiter, 2));
	}
	else
	{
	/*	waiter->tdie2[waiter->id - 1] = waiter->tdie;
		waiter->nb_eat[waiter->id - 1] += 1;*/
		sem_post(waiter->fork);
		sem_post(waiter->fork);
		waiter->tdie2[waiter->id - 1] = waiter->tdie;
		waiter->nb_eat[waiter->id - 1] += 1;
		return(check_die_eat(waiter, 0));
	}
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
//		usleep(1000 * (waiter->id));
		if(fork_lock_unlock(waiter, 1) == 1)
			break;
//		waiter->last_eat[waiter->id - 1] = time;
		ft_display(waiter, 1);
		ft_display(waiter, 2);
		usleep(waiter->teat * 990);
//		fork_lock_unlock(waiter, 0, 0, time);
//		time += (waiter->last_eat[waiter->id - 1] + waiter->teat - time);
		if(fork_lock_unlock(waiter, 0) == 1)
			break;
/*		if(check_die_eat(waiter, 0) == 1)
			break;*/
		ft_display(waiter, 3);
		usleep(waiter->tsleep * 990);
//		time += (waiter->last_eat[waiter->id - 1] + waiter->teat + waiter->tsleep - time);
		if(check_die_eat(waiter, 0) == 1)
			break;
		ft_display(waiter, 4);
	}
	return (NULL);
}

sem_t **init_semtab(char **av)
{
	sem_t **tab;

	sem_unlink("/display");
	sem_unlink("/forks");
	if(!(tab = (sem_t **)malloc(sizeof(sem_t *) * 2)))
		return (0);
	tab[0] = init_sem(ft_atoi(av[1]), "/forks");
	tab[1] = init_sem(1, "/display");
	return (tab);
}

int main(int ac, char **av)
{
	t_waiter *waiter;
	long **tab;
	int i;
	sem_t **sem_tab;
	pthread_t *tid;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		sem_tab = init_semtab(av);
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
		tab = init_tab(av);
		while(i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->display = sem_tab[1];
			waiter->fork = sem_tab[0];
			pthread_create(&tid[i++], NULL, &dinner, (void *)(waiter));
		}
		i = 0;
		while(i < ft_atoi(av[1]))
			pthread_join(tid[i++], NULL);
	}
	return (0);
}
