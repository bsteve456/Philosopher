/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:52:40 by blacking          #+#    #+#             */
/*   Updated: 2020/06/10 16:04:14 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	sem_t *forks;
	int n;

	forks = sem_open("/forks", O_CREAT, S_IRWXU, 5);
	sem_getvalue(forks, &n);
	printf("n : %d\n", n);
	sem_wait(forks);
	sem_getvalue(forks, &n);
	printf("n : %d\n", n);
	sem_post(forks);
	sem_getvalue(forks, &n);
	printf("n : %d\n", n);
	sem_unlink("/forks");
}
