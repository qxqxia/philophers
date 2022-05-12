/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:51:09 by qxia              #+#    #+#             */
/*   Updated: 2022/05/10 11:19:28 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_enough_eat(t_philo *each_philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (each_philo->info_utils->nbr_philo_must_eat == 0)
		return (0);
	while (i < each_philo->info_utils->nbr_philo)
	{
		if (each_philo->nbr_eat >= each_philo->info_utils->nbr_philo_must_eat)
			count++;
		i++;
	}
	if (count == each_philo->info_utils->nbr_philo)
	{
		return (1);
	}
	return (0);
}

int	check_died(t_philo *each_philo)
{
	if (each_philo->last_meal != 0
		&& (get_time() - each_philo->last_meal
			> each_philo->info_utils->ttdie))
	{
		pthread_mutex_lock(&each_philo->info_utils->mutex);
		philo_state(each_philo, 4);
		each_philo->info_utils->check_died = 1;
		pthread_mutex_unlock(&each_philo->info_utils->mutex);
		return (0);
	}
	return (1);
}
