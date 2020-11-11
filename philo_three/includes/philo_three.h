/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/11/11 21:41:03 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <string.h>

# define RESET 10000

typedef struct		s_msg
{
	int					msg;
	long				time;
}					t_msg;

typedef struct	s_waiter
{
	int					nthread;
	long				tdie;
	long				teat;
	long				tsleep;
	long				ntoeat;
	long				nb_eat;
	long				last_eat;
	long				j;
	long				i;
	long				s;
	long				id;
	int					end;
	sem_t				*fork;
	sem_t				*display;
	t_msg				*msg;
}				t_waiter;
t_waiter	*init_waiter(char **av, int ac);
int			p_is_dead(t_waiter *waiter, int id);
int			ft_atoi(const char *str);
int			check_state(t_waiter *waiter, int id, int pos);
void		ft_display(t_waiter *waiter, int n, int id);
long		utime(void);
t_msg		*fill_msg(void);
void		think_msg(t_waiter *waiter);
int			lock_fork(t_waiter *waiter);
int			lock_fork2(t_waiter *waiter);
int			unlock_fork(t_waiter *waiter);
void		usleep_eat(t_waiter *waiter);
void		usleep_sleep(t_waiter *waiter);
void		*ft_calloc(size_t count, size_t size);
void		*monitor(void *arg);
void		has_afork(int id, long time);
void		is_eating(int id, long time);
void		is_sleeping(int id, long time);
void		is_thinking(int id, long time);
void		is_dead(int id, long time);
int			philo_state(t_waiter *waiter);
void		dis_msg(int id, int msg, long time);
void		dis_utils(long time, int id);
void		ft_putstr(char *s);

#endif
