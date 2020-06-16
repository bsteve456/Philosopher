/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/16 17:18:13 by blacking         ###   ########.fr       */
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


typedef struct	s_waiter
{
	long				tdie;
	long			tdie2;
	long				teat;
	long				tsleep;
	long				ntoeat;
	long				last_eat;
	sem_t			*fork;
	sem_t			*display;
}				t_waiter;
t_waiter	*init_waiter(char **av, int ac);
int			p_is_dead(t_waiter *waiter, int id);
int			ft_atoi(const char *str);
int			check_state(t_waiter *waiter, int id, int pos);
void		ft_display(t_waiter *waiter, int n, int id);
long			utime();
#endif
