/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/18 19:55:04 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct	s_waiter
{
	int					nthread;
	long				tdie;
	long				teat;
	long				tsleep;
	int					ntoeat;
	long				*tdie2;
	long				*nb_eat;
	long				*last_eat;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*display;
	int					id;
	int					*fn;
}				t_waiter;
long			*ft_tdie(int nthread, long tdie);
long			*ft_nb_eat(int nthread);
long			*ft_last_eat(int nthread);
long			**init_tab(char **av);
t_waiter		*init_waiter(char **av, long **tab, int i, int ac);
//int				check_die_eat(t_waiter *waiter, int pos);
int				fork_number(int id, int pos, int last);
void			ft_display(t_waiter *waiter, int n, long time);
int				ft_atoi(const char *str);
long			utime(void);
pthread_mutex_t	*init_mutex(int n);
void			display2(long time, int id, int n);
int				check_state(t_waiter *waiter);
int				philo_state(t_waiter *waiter);
void			ft_putnbr(long n);
void			ft_putstr(char *s);
void			dis_utils(long time, int id);
int				lock_fork(t_waiter *waiter);
int				lock_fork2(t_waiter *waiter);
int				unlock_fork(t_waiter *waiter);
void			has_afork(int id, long time);
void			is_eating(int id, long time);
void			is_sleeping(int id, long time);
void			is_thinking(int id, long time);
void			is_dead(int id, long time);
void			test(int id, long time);
#endif
