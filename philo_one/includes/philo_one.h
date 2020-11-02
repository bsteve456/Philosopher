/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:35:20 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/02 15:16:20 by stbaleba         ###   ########.fr       */
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

typedef struct		s_msg
{
	int					msg;
	long				time;
}					t_msg;

typedef struct		s_waiter
{
	int					nthread;
	long				tdie;
	unsigned int		teat;
	unsigned int		tsleep;
	int					ntoeat;
	long				*tdie2;
	long				*nb_eat;
	long				*last_eat;
	int					id;
	int					j;
	int					*dead;
	t_msg				**msg;
	char				**tab;
	long				s;
}					t_waiter;
long				*ft_tdie(int nthread, long tdie);
long				*ft_nb_eat(int nthread);
long				*ft_last_eat(int nthread);
long				**init_tab(char **av);
t_waiter			*init_waiter(char **av, long **tab, int i, int ac);
int					ft_atoi(const char *str);
long				utime(void);
pthread_mutex_t		*init_mutex(int n);
int					philo_state(t_waiter *waiter, int thread);
void				ft_putnbr(long n);
void				ft_putstr(char *s);
void				dis_utils(long time, int id);
int					lock_fork(t_waiter *waiter);
int					lock_fork2(t_waiter *waiter);
int					unlock_fork(t_waiter *waiter);
void				has_afork(int id, long time);
void				is_eating(int id, long time);
void				is_sleeping(int id, long time);
void				is_thinking(int id, long time);
void				is_dead(int id, long time, int *ndie);
void				display_all_msg(t_waiter *waiter, long time);
void				dis_msg(int id, int msg, long time, t_waiter *waiter);
void				*ft_calloc(size_t count, size_t size);
t_msg				*fill_msg();
void				usleep_eat(t_waiter *waiter);
void				usleep_sleep(t_waiter *waiter);
void				usleep_ntime(int n);
int					left(int x, int y);
void				init_pthread_tab(pthread_t **tid, t_msg ***tab, char *av);
void				mring_dis(t_msg **tab, int *pos, t_waiter *waiter);
void 				think_msg(t_waiter *waiter);
pthread_mutex_t		*init_fork(int n);

#endif
