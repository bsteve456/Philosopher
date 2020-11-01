/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/10/21 10:36:48 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

# include <string.h>
# define RESET 10000
# define LEFT(X, Y)  (X % Y)
# define RIGHT(X) (X - 1)
typedef struct	s_msg
{
	int					msg;
	long				time;
}				t_msg;

typedef struct	s_waiter
{
	int				nthread;
	long				tdie;
	unsigned int				teat;
	unsigned int				tsleep;
	int				ntoeat;
	long				*tdie2;
	long				*nb_eat;
	long				*last_eat;
	long					*display2;
	pthread_mutex_t			*fork;
	pthread_mutex_t			*display;
	int				id;
	int				j;
	int				*fn;
	int				*dead;
	t_msg			**msg;
	char			**tab;
}				t_waiter;
long			*ft_tdie(int nthread, long tdie);
long			*ft_nb_eat(int nthread);
long			*ft_last_eat(int nthread);
long			**init_tab(char **av);
t_waiter		*init_waiter(char **av, long **tab, int i, int ac);
int			fork_number(int id, int pos, int last);
int			ft_atoi(const char *str);
long			utime(void);
pthread_mutex_t		*init_mutex(int n);
int			philo_state(t_waiter *waiter, int thread, long time);
void			ft_putnbr(long n);
void			ft_putstr(char *s);
void			dis_utils(long time, int id);
int			lock_fork(t_waiter *waiter);
int			lock_fork2(t_waiter *waiter);
int			unlock_fork(t_waiter *waiter);
void			has_afork(int id, long time);
void			is_eating(int id, long time);
void			is_sleeping(int id, long time);
void			is_thinking(int id, long time);
void			is_dead(int id, long time);
void			display_all_msg(t_waiter *waiter, long time);
void			display_msg(int id, int msg, long time, t_waiter *waiter);
void			*ft_calloc(size_t count, size_t size);
t_msg			*fill_msg();
void			usleep_eat(t_waiter *waiter);
void			usleep_sleep(t_waiter *waiter);
void			usleep_ntime(int n);

#endif
