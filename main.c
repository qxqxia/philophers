/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:46:57 by qxia              #+#    #+#             */
/*   Updated: 2022/04/15 15:34:11 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		return (error_exit("Error: incorrect arguments\n"));
	if (start_threads(&philo))
		return 
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock();
	return (0);
}

