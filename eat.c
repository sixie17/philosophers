/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:59:52 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 17:06:15 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*eat(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *) philo;
	if (philosopher->id % 2)
		usleep(1100);
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d has taken a fork\n",
		time_passed(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	pthread_mutex_lock(philosopher->right_fork);
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d has taken a fork\n",
		time_passed(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms philosopher %d is eating\n",
		time_passed(philosopher->start), philosopher->id);
	pthread_mutex_unlock(philosopher->print);
	usleep(philosopher->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
	philosopher->last_meal = time_passed(0);
	ft_sleep(philosopher);
	return (NULL);
}
