/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:52:41 by blacking          #+#    #+#             */
/*   Updated: 2020/06/02 15:02:08 by blacking         ###   ########.fr       */
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
	void *id;
}				t_waiter;

#endif
