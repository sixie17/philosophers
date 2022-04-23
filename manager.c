/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:37 by ysakine           #+#    #+#             */
/*   Updated: 2022/04/23 12:57:20 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_sleep(t_philo *philosopher, long long start)
{
	long long	tmp;

	printf("%lld %d is sleeping", ft_get_elapsed_time(start), philosopher->id);
	tmp = ft_get_elapsed_time(0);
	philosopher->sleeping = 1;
	ft_usleep(philosopher->time_to_sleep);
	philosopher->time_left -= ft_get_elapsed_time(tmp);
	philosopher->sleeping = 0;
}

void	eat(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork);
	printf("[%lld] %d has taken a fork", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_lock(&philosopher->right_fork);
	printf("[%lld] %d has taken a fork", ft_get_elapsed_time(philosopher->start), philosopher->id);
	printf("%lld %d is eating", ft_get_elapsed_time(philosopher->start), philosopher->id);
	philosopher->is_eating = 1;
	ft_usleep(philosopher->time_to_eat);
	philosopher->time_left -= philosopher->time_to_eat;
	pthread_mutex_unlock(&philosopher->left_fork);
	pthread_mutex_unlock(&philosopher->right_fork);
	philosopher->is_eating = 0;
	philosopher->time_left = philosopher->life_time;
	ft_sleep(philosopher, philosopher->start);
}


void	think(t_philo *philosopher, long long start)
{
	printf("%lld %d is thinking", ft_get_elapsed_time(start), philosopher->id);
}

void	init_mutex(pthread_mutex_t *mutex, t_philo *philosophers, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < num)
	{
		philosophers[i].left_fork = mutex[j % num];
		philosophers[i].right_fork = mutex[(j + 1) % num];
		i++;
		j += 2;	
	}
	
}

void	manage_philosopers(t_philo *philosphers, int num)
{
	pthread_mutex_t 	*forks;
	int					i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!forks)
		exit(0);
	init_mutex(forks, philosphers, num);
	while (i < num)
	{
		philosphers[i].start = ft_get_elapsed_time(0);
		pthread_create(&philosphers[i].philo_thread, NULL, &eat, &philosphers[i]);
		i++;
	}
	i = 0;
	while (i < num)
	{
		pthread_join(philosphers[i].philo_thread, NULL);
		i++;
	}
}