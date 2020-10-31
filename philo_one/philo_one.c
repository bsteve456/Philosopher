#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;
	static pthread_mutex_t *fork = 0;
	long start;

	waiter = arg;
	if(fork == 0 && waiter->id - 1 == 0)
	{
		if (!(fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t ) * waiter->nthread)))
			return (NULL);
	}
	else
		usleep(1000);
	start = utime();
	waiter->msg[waiter->id - 1][waiter->j].msg = 5;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
	if ((waiter->id) % 2 == 0)
		usleep(1000);
	while(1)
	{
		pthread_mutex_lock(&(fork[LEFT(waiter->id, waiter->nthread)]));
		lock_fork(waiter);
		pthread_mutex_lock(&(fork[waiter->id - 1]));
		lock_fork2(waiter);
		usleep_eat(waiter);
		pthread_mutex_unlock(&(fork[waiter->id - 1]));
		pthread_mutex_unlock(&(fork[LEFT(waiter->id, waiter->nthread)]));
		if (unlock_fork(waiter) == 1)
			break;
		usleep_sleep(waiter);
		waiter->msg[waiter->id - 1][waiter->j].msg = 5;
		waiter->msg[waiter->id - 1][waiter->j].time = utime();
		waiter->j += 1;
		if(waiter->j == RESET)
		{
			waiter->msg[waiter->id - 1] = fill_msg();
			waiter->j = 0;
			write(1, "ok\n", 4);
		}
		if (philo_state(waiter, 1, start) == 1)
			break;
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

void	check_state(t_waiter *waiter, char *msg, long time)
{
	int i;
	long *last;
	long teat;
	long tsleep;

	last = waiter->last_eat;
	teat = waiter->teat;
	tsleep = waiter->tsleep;
	i = 0;
	while (i < waiter->nthread)
	{
		if (msg[i] == 2 && last[i] + teat < time)
			printf("[last :%ld eat:%ld time : %ld] %d eat too long\n", last[i], teat ,time ,i + 1);
		else if (msg[i] == 4 && last[i] + teat + tsleep < time)
			printf("[last :%ld tsleep: %ld time : %ld] %d sleep too long\n", last[i], tsleep, time ,i + 1);
		i++;
	}
}

void	monitoring_loop(t_waiter *waiter, long start_time)
{
	t_msg **tab;
	int	i;
	int *pos;
	int j;
	char *msg;
	// long time;

	if (!(tab = (t_msg **)malloc(sizeof(t_msg *) * waiter->nthread)))
		return ;
	if (!(msg = ft_calloc(sizeof(char), waiter->nthread)))
		return ;
	if(!(pos = (int *)malloc(sizeof(int) * waiter->nthread)))
		return ;
	i = 0;
	while(i < waiter->nthread)
	{
		tab[i] = waiter->msg[i];
		pos[i] = 0;
		i++;
	}
	usleep_ntime(20);
	while(1)
	{
//		time = utime();
//		check_state(waiter, msg, time);
		if(philo_state(waiter, 0, start_time) == 1)
				return ;
		i = 0;
		while (i < waiter->nthread)
		{
			j = pos[i];
			if(tab[i][j].msg != 0 && tab[i][j].time != 0)
			{
				msg[i] = tab[i][j].msg;
				display_msg(i + 1, tab[i][j].msg, tab[i][j].time - start_time, waiter);
				pos[i] = j + 1;
			}
			if(pos[i] == RESET)
			{
				free(tab[i]);
				tab[i] = waiter->msg[i];
				pos[i] = 0;
			}
			i++;
		}
		usleep(8000);
	}
}

int main(int ac, char **av)
{
	t_waiter	*waiter;
	long		**tab;
	int			i;
	pthread_t	*tid;
	pthread_mutex_t **mutex;
	t_msg		**tab2;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
		if(!(tab2 = (t_msg **)malloc(sizeof(t_msg *) * ft_atoi(av[1]))))
			return (0);
		while (i < ft_atoi(av[1]))
			tab2[i++] = fill_msg();
		i = 0;
		tab = init_tab(av);
		mutex = init_mutex_tab(av);
		while(i < ft_atoi(av[1]))
		{
			waiter = init_waiter(av, tab, i, ac);
			waiter->fork = mutex[0];
			waiter->display = mutex[1];
			waiter->last_eat[waiter->id - 1] = utime();
			waiter->msg = tab2;
			waiter->j = 0;
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			pthread_detach(tid[i++]);
		}
		monitoring_loop(waiter, utime());
	}
	return (0);
}
