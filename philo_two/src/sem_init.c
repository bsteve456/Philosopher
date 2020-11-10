/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:21:11 by stbaleba          #+#    #+#             */
/*   Updated: 2020/11/10 14:23:58 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

sem_t		*init_sem(int n, char *str)
{
	sem_t *res;

	if (n == 1 && *(str + 1) == 'f')
		n++;
	res = sem_open(str, O_CREAT, S_IRWXU, n);
	return (res);
}
