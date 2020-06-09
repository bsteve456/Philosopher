/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/09 16:18:33 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct	s_waiter
{
	int	nthread;
	int	tdie;
	int	teat;
	int tsleep;
	int ntoeat;
	int *tdie2;
	int *nb_eat;
	int *last_eat;
	pthread_mutex_t *fork;
	int id;
}				t_waiter;
int			*ft_tdie(int nthread, int tdie);
int			*ft_nb_eat(int nthread);
int			*ft_last_eat(int nthread);
int			**init_tab(char **av);
t_waiter	*init_waiter(char **av, int **tab, int i, int ac);
int			check_state(t_waiter *waiter, int time);
int			check_die_eat(t_waiter *waiter, int time, int pos, int slep);
int			fork_number(int id, int pos, int last);
#endif
