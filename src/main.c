/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:51:30 by qxia              #+#    #+#             */
/*   Updated: 2022/05/10 11:38:32 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	creat_pthread(t_data *data, t_philo *each_philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->fork[i++], NULL) != 0)
			return (FAILURE);
	}
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&data->mutex_died, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		return (FAILURE);
	i = 0;
	while (i < data->nbr_philo)
	{
		each_philo[i].info_utils = data;
		if (pthread_create(&(each_philo[i].philo),
				NULL, routine, (void *)&(each_philo[i])) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	run_pthread(t_data *data, t_philo *each_philo)
{
	int	i;

	if (creat_pthread(data, each_philo) != SUCCESS)
		return (FAILURE);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(each_philo[i++].philo, NULL) != 0)
			return (FAILURE);
	}
	i = 0;
	return (SUCCESS);
}

static int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_atoi(av[i]) > INT32_MAX)
				return (FAILURE);
			if (av[i][0] == '-')
				return (FAILURE);
			if (av[i][0] == '0' && av[i][1] == '\0')
				return (FAILURE);
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_philo	*each_philo;
	t_data	*philo_info;

	if (ac > 6 || ac < 5)
		return (ft_exit("Args Error", NULL, NULL, FAILURE));
	if (check_args(av) == FAILURE)
		return (ft_exit("Args Error", NULL, NULL, FAILURE));
	each_philo = init_each_philo(ft_atoi(av[1]));
	if (!each_philo)
		return (ft_exit("Init Error", each_philo, NULL, FAILURE));
	philo_info = init_value(av);
	if (!philo_info)
		return (ft_exit("Init Error", each_philo, philo_info, FAILURE));
	philo_info->start_time = get_time();
	if (philo_info->start_time == -1)
		return (ft_exit("Time Error", each_philo, philo_info, FAILURE));
	if (run_pthread(philo_info, each_philo) == FAILURE)
		return (ft_exit("Pthread Error", each_philo, philo_info, FAILURE));
	return (ft_exit(NULL, each_philo, philo_info, SUCCESS));
}
