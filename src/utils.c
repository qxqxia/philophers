/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:51:47 by qxia              #+#    #+#             */
/*   Updated: 2022/05/12 10:20:33 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void *data)
{
	if (data)
		free(data);
	data = NULL;
}

int	ft_exit(char *msg, t_philo *each_philo, t_data *data, int ret)
{
	if (msg)
		printf("%s\n", msg);
	if (data)
	{
		if (data->fork)
			ft_free(data->fork);
	}
	if (each_philo)
	{
		if (each_philo->info_utils)
			ft_free(each_philo->info_utils);
		ft_free(each_philo);
	}
	return (ret);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
		memset(ptr, 0, count * size);
	return (ptr);
}

long	ft_atoi(const char *str)
{
	int		signe;
	long	res;

	signe = 1;
	res = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || (*str == ' ')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res * signe);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (FAILURE);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}
