/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:00:36 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 15:33:18 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_sleep(void *philo)
{
	t_philo *philosophers;

	philosophers = (t_philo *) philo;
	philosophers->sleeping = 1;
	pthread_mutex_lock(philosophers->print);
	printf("%lld ms philosopher %d is sleeping\n", ft_get_elapsed_time(philosophers->start), philosophers->id);
	pthread_mutex_unlock(philosophers->print);
	usleep(philosophers->time_to_sleep * 1000);
	pthread_mutex_lock(philosophers->print);
	printf("%lld ms philosopher %d is thinking\n", ft_get_elapsed_time(philosophers->start), philosophers->id);
	pthread_mutex_unlock(philosophers->print);
	philosophers->sleeping = 0;
	eat(philosophers);
	return (NULL);
}