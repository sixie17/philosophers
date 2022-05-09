/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:59:52 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 16:33:16 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*eat(void *philo)
{
	t_philo *philosopher;

	philosopher = (t_philo *) philo;
	if (philosopher->id % 2)
		usleep(1100);
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d has taken a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	pthread_mutex_lock(philosopher->right_fork);
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d has taken a fork\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	philosopher->is_eating = 1;
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d is eating\n", ft_get_elapsed_time(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	usleep(philosopher->time_to_eat * 1000);
	philosopher->time_left = philosopher->life_time;
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
	philosopher->last_meal = ft_get_elapsed_time(0);
	philosopher->is_eating = 0;
	ft_sleep(philosopher);
	return (NULL);
}