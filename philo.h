/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:10:54 by qxia              #+#    #+#             */
/*   Updated: 2022/04/14 11:10:16 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

#define FAILURE 1
#define SUCCESS 0

typedef struct s_each_philo
{
	phread_t		philo;
	int				id;
	int				nbr_eat;
	long long		last_meal;
	struct s_philo	*info_utils;
}t_each_philo;

typedef struct s_philo
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_philo_must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex;
}t_philo;


