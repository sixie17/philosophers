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


void	*ft_sleep(void *philo)
{
	t_philo *philosophers;

	philosophers = (t_philo *) philo;
	philosophers->sleeping = 1;
	printf("[%lld] philosopher %d is sleeping\n", ft_get_elapsed_time(philosophers->start), philosophers->id);
	ft_usleep(philosophers->time_to_sleep);
	philosophers->sleeping = 0;
	return (NULL);
}

void	*eat(void *philo)
{
	t_philo *philosopher;

	philosopher = (t_philo *) philo;
	pthread_mutex_lock(philosopher->left_fork);
	printf("[%lld] philosopher %d has taken a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_lock(philosopher->right_fork);
	printf("[%lld] philosopher %d has taken a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	philosopher->is_eating = 1;
	printf("[%lld] philosopher %d is eating\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	ft_usleep(philosopher->time_to_eat);
	philosopher->time_left = philosopher->life_time;
	pthread_mutex_unlock(philosopher->left_fork);
	printf("[%lld] philosopher %d has left a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->right_fork);
	printf("[%lld] philosopher %d has left a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	philosopher->last_meal = ft_get_elapsed_time(0);
	philosopher->is_eating = 0;
	ft_sleep(philosopher);
	return (NULL);
}


void	init_mutex(pthread_mutex_t *mutex, t_philo *philosophers, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num)
	{
		pthread_mutex_init(mutex + i, NULL);
		//pthread_mutex_init(philosophers[i].print, NULL);
		i++;
	}
	i = 0;
	while (i < num)
	{
		philosophers[i].left_fork = &mutex[j % num];
		philosophers[i].right_fork = &mutex[(j + 1) % num];
		i++;
		j += 2;	
	}
	
}

// void	*action(void *philos)
// {

// }

void	manage_philosopers(t_philo *philosophers, int num)
{
	pthread_mutex_t 	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * num);;
	if (!forks)
		exit(0);
	init_mutex(forks, philosophers, num);
	while (1)
	{
		i = 0;
		while (i < num)
		{
			pthread_create(&philosophers[i % num].philo_thread, NULL, &eat, &philosophers[i % num]);
			// if ((i - 1) % num < num / 2)
			// 	ft_usleep(philosophers[i].time_to_eat);		
			//pthread_create(&philosophers[i % num].philo_thread, NULL, &eat, &philosophers[i % num]);
			if (!philosophers[i % num].sleeping && !philosophers[i % num].is_eating)
				printf("[%lld] philosopher %d is thinking\n", ft_get_elapsed_time(philosophers[i % num].start), philosophers[i % num].id);
			if (philosophers[i % num].time_left - ft_get_elapsed_time(philosophers[i % num].last_meal) <= 0)
			{
				printf("[%lld] philosopher %d is dead\n", ft_get_elapsed_time(philosophers[i % num].start), philosophers[i % num].id);
				exit(0);
			}
			++i;
		}
	}
}