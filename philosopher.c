/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:46:21 by ysakine           #+#    #+#             */
/*   Updated: 2022/04/23 12:37:00 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philos(t_philo *philo, t_args args)
{
	int	i;

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
	}
}
