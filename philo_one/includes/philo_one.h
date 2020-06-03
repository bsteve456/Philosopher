/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/03 16:37:30 by blacking         ###   ########.fr       */
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
	int ntoeat;
	int *fork;
	int *tdie2;
	int *nb_eat;
	void *id;
}				t_waiter;
int			*ft_fork(int nthread);
int			*ft_tdie(int nthread, int tdie);
int			*ft_nb_eat(int nthread);
int			**init_tab(char **av);
t_waiter	*init_waiter(char **av, int **tab, int i, int ac);
#endif
