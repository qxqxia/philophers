/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:46:57 by qxia              #+#    #+#             */
/*   Updated: 2022/04/14 15:49:10 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++; // read mails et increment et write mails
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

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

