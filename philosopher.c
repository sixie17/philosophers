/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:46:21 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 15:30:53 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philos(t_philo *philo, t_args args)
{
	int				i;

	i = 0;
	while (i < args.number_of_philosopher)
	{
		philo[i].id = i;
		philo[i].life_time = args.time_to_die;
		philo[i].time_left = args.time_to_die;
		philo[i].time_to_eat = args.time_to_eat;
		philo[i].time_to_sleep = args.time_to_sleep;
		philo[i].is_eating = 0;
		philo[i].sleeping = 0;
		philo[i].is_dead = 0;
		i++;
	}
}

void	init_mutex(pthread_mutex_t *mutex, t_philo *philosophers, int num, pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philosophers[i].print = print;
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < num)
	{
		philosophers[i].left_fork = &mutex[i % num];
		philosophers[i].right_fork = &mutex[(i + 1) % num];
		i++;	
	}
}

void	init_start(t_philo * philo, int num)
{
	long long		start;
	int				i;

	i = 0;
	start = ft_get_elapsed_time(0);
	while (i < num)
	{
		philo[i].last_meal = start;
		philo[i].start = start;
		i++;
	}
}

