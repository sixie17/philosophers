/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:37 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/10 15:30:09 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutexes(pthread_mutex_t *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	check_eat(t_philo *philos, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (philos[0].the_num)
			return (0);
		i++;
	}
	return (1);
}

int	check_death(t_philo *philos, int num)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < num)
		{
			if (philos[i % num].life_time
				< time_passed(philos[i % num].last_meal))
			{
				pthread_mutex_lock(philos[i].print);
				printf("%lld ms philosopher %d died\n",
					time_passed(philos[i % num].start), philos[i % num].id);
				usleep(100);
				return (1);
			}
			i++;
		}
		if (philos->has_num && check_eat(philos, num))
			return (1);
	}
	return (0);
}

void	manage_philosopers(t_philo *philosophers, int num)
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	int					i;

	forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!forks)
		return ;
	pthread_mutex_init(&print, NULL);
	init_mutex(forks, philosophers, num, &print);
	i = 0;
	init_start(philosophers, num);
	while (i < num)
	{
		pthread_create(&philosophers[i].philo_thread, NULL,
			&eat, &philosophers[i]);
		i++;
	}
	if (check_death(philosophers, num))
	{
		free(forks);
		destroy_mutexes(forks, num);
		return ;
	}
}
