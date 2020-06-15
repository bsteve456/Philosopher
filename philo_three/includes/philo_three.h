/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/15 22:45:57 by blacking         ###   ########.fr       */
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
	int				tdie;
	int				tdie2;
	int				teat;
	int				tsleep;
	int				ntoeat;
	int				last_eat;
	sem_t			*fork;
	sem_t			*display;
}				t_waiter;
t_waiter	*init_waiter(char **av, int ac);
int			p_is_dead(t_waiter *waiter, int id);
int			ft_atoi(const char *str);
#endif
