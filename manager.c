/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:37 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 15:30:06 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	manage_philosopers(t_philo *philosophers, int num)
{
	pthread_mutex_t 	*forks;
	pthread_mutex_t 	print;
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
		pthread_create(&philosophers[i % num].philo_thread, NULL, &eat, &philosophers[i % num]);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < num)
		{
			if (philosophers[i % num].life_time < ft_get_elapsed_time(philosophers[i % num].last_meal))
			{
				pthread_mutex_lock(&print);
				printf("%lld ms philosopher %d is dead\n", ft_get_elapsed_time(philosophers[i % num].start), philosophers[i % num].id);
				usleep(100);
				return ;
			}
			i++;
		}
	}
}