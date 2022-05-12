/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:51:21 by qxia              #+#    #+#             */
/*   Updated: 2022/05/12 10:20:01 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_value(char **av)
{
	t_data	*data;

	data = ft_calloc (sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->nbr_philo = ft_atoi(av[1]);
	data->ttdie = ft_atoi(av[2]);
	data->tteat = ft_atoi(av[3]);
	data->ttsleep = ft_atoi(av[4]);
	data->check_died = 0;
	if (av[5] && ft_atoi(av[5]) > 0)
		data->nbr_philo_must_eat = ft_atoi(av[5]);
	data->fork = ft_calloc(sizeof(pthread_mutex_t), data->nbr_philo);
	if (!data->fork)
		return (NULL);
	return (data);
}

t_philo	*init_each_philo(int philo_nbr)
{
	t_philo	*each_philo;
	int		i;

	i = 0;
	each_philo = ft_calloc(sizeof(t_data), philo_nbr);
	if (!each_philo)
		return (NULL);
	while (i < philo_nbr)
	{
		each_philo[i].id = i + 1;
		each_philo[i].nbr_eat = 0;
		each_philo[i].last_meal = 0;
		i++;
	}
	return (each_philo);
}

int	state_mutex(t_philo *each_philo, int state)
{
	static int	state_state;

	pthread_mutex_lock(&each_philo->info_utils->mutex_died);
	if (state_state != 0)
	{
		pthread_mutex_unlock(&each_philo->info_utils->mutex_died);
		return (1);
	}
	pthread_mutex_unlock(&each_philo->info_utils->mutex_died);
	if (state == 4)
	{
		pthread_mutex_lock(&each_philo->info_utils->mutex_died);
		state_state = 1;
		pthread_mutex_unlock(&each_philo->info_utils->mutex_died);
	}
	else if (check_enough_eat(each_philo))
	{
		return (1);
	}
	return (0);
}

void	philo_state(t_philo *each_philo, int state)
{
	const char	*states[] = {"is eating", "has taken a fork",
		"is sleeping", "is thinking", "died"};

	pthread_mutex_lock(&each_philo->info_utils->mutex_print);
	if (state_mutex(each_philo, state) == 1)
	{
		pthread_mutex_unlock(&each_philo->info_utils->mutex_print);
		return ;
	}
	printf("[%lld] philosopher[%d] %s\n",
		get_time() - (each_philo->info_utils->start_time),
		each_philo->id, states[state]);
	pthread_mutex_unlock(&each_philo->info_utils->mutex_print);
}

void	ft_usleep(long long ms, t_philo *each_philo)
{
	const long long	start = get_time();

	while (get_time() - start < ms && check_died(each_philo)
		&& !check_enough_eat(each_philo))
		usleep(MICRO_SECOND);
}
