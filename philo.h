/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:50:43 by qxia              #+#    #+#             */
/*   Updated: 2022/05/11 14:06:27 by qinxia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>

# define FAILURE 1
# define SUCCESS 0
# define MICRO_SECOND 400

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				nbr_eat;
	long long		last_meal;
	struct s_data	*info_utils;
}		t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				nbr_philo_must_eat;
	long long		start_time;
	int				check_died;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_died;
}		t_data;

long			ft_atoi(const char *str);
int				main(int ac, char **av);
t_data			*init_value(char **av);
t_philo			*init_each_philo(int philo_nbr);
int				ft_exit(char *msg, t_philo *each_philo,
					t_data *data, int ret);
void			ft_free(void *data);
void			*ft_calloc(size_t count, size_t size);
long long		get_time(void);
int				state_mutex(t_philo *each_philo, int state);
void			philo_state(t_philo *each_philo, int state);
void			*routine(void *each_philo);
void			ft_usleep(long long ms, t_philo *each_philo);
int				check_died(t_philo *each_philo);
int				check_enough_eat(t_philo *each_philo);

#endif
