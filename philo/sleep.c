/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:00:36 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/10 15:17:48 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_sleep(void *philo)
{
	t_philo	*philosophers;

	philosophers = (t_philo *) philo;
	pthread_mutex_lock(philosophers->print);
	printf("%lld ms philosopher %d is sleeping\n",
		time_passed(philosophers->start), philosophers->id);
	pthread_mutex_unlock(philosophers->print);
	usleep(philosophers->time_to_sleep * 1000);
	pthread_mutex_lock(philosophers->print);
	printf("%lld ms philosopher %d is thinking\n",
		time_passed(philosophers->start), philosophers->id);
	pthread_mutex_unlock(philosophers->print);
	eat(philosophers);
	return (NULL);
}
