#include "philo_one.h"

void	*dinner(void *arg)
{
	t_waiter *waiter;

	waiter = arg;

	waiter->msg[waiter->id - 1][waiter->j].msg = 5;
	waiter->msg[waiter->id - 1][waiter->j].time = utime();
	waiter->j += 1;
/*	pthread_mutex_lock(waiter->display);
	msgadd_back(waiter, msgnew(waiter->id, 5, utime()));
	pthread_mutex_unlock(waiter->display);*/
	usleep(300 * waiter->id);
	while(1)
	{
//		if(lock_fork(waiter) == 1)
//			break;
		lock_fork(waiter);
//		if(lock_fork2(waiter) == 1)
//			break;
		lock_fork2(waiter);
		usleep(waiter->teat);
//		if(unlock_fork(waiter) == 1)
//			break;
		unlock_fork(waiter);
		usleep(waiter->tsleep);
//		if(philo_state(waiter, 1, 0) == 1)
//			break;
/*		pthread_mutex_lock(waiter->display);
		msgadd_back(waiter, msgnew(waiter->id, 5, utime()));
		pthread_mutex_unlock(waiter->display);*/
		waiter->msg[waiter->id - 1][waiter->j].msg = 5;
		waiter->msg[waiter->id - 1][waiter->j].time = utime();
		waiter->j += 1;
		if(waiter->j == RESET)
		{
			waiter->msg[waiter->id - 1] = fill_msg();
			waiter->j = 0;
			write(1, "ok\n", 4);
		}
		if(philo_state(waiter, 1, 0) == 1)
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


void	monitoring_loop(t_waiter *waiter)
{
//	t_msg *lst;
//	t_msg *mem;
	t_msg **tab;
	long time;
	int	i;
	int *pos;
	int j;
//	lst = waiter->msg;
//	mem = 0;
	if (!(tab = (t_msg **)malloc(sizeof(t_msg *) * waiter->nthread)))
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
	while(1)
	{
//		pthread_mutex_lock(waiter->display);
		time = utime();
//		pthread_mutex_unlock(waiter->display);
		if(philo_state(waiter, 0, time) == 1)
				return ;
/*		if(lst->next != NULL)
		{
			free(mem);
			display_msg(lst->id, lst->msg, lst->time, waiter);
			mem = lst;
			lst = lst->next;
		}i*/
		i = 0;
		while (i < waiter->nthread)
		{
			j = pos[i];
			if(tab[i][j].msg != 0)
			{
				display_msg(i + 1, tab[i][j].msg, tab[i][j].time, waiter);
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
		usleep(1000);
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
//	char 		**tab1;

	i = 0;
	if(ac >= 5 && ft_atoi(av[1]) > 0)
	{
		if (!(tid = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]) + 1)))
			return (0);
//		if(!(tab1 = (char **)malloc(sizeof(char *) * ft_atoi(av[1]))))
//			return (0);
		if(!(tab2 = (t_msg **)malloc(sizeof(t_msg *) * ft_atoi(av[1]))))
			return (0);
//		while (i < ft_atoi(av[1]))
//			tab1[i++] = ft_calloc(sizeof(char *), RESET);
		while (i < ft_atoi(av[1]))
			tab2[i++] = fill_msg();
		i = 0;
//		lst = msgnew(0, 0, 0);
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
//			waiter->tab = tab1;
			pthread_create(&tid[i], NULL, &dinner, (void *)(waiter));
			pthread_detach(tid[i++]);
		}
		monitoring_loop(waiter);
	}
	return (0);
}
