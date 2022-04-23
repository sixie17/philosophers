/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:38:56 by ysakine           #+#    #+#             */
/*   Updated: 2022/04/23 12:22:56 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSEPHERS_H
#define PHILOSEPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/time.h>

typedef struct	s_args
{
	int			number_of_philosopher;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		philo_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	long long		time_left;
	long long		life_time;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start;
	int				is_eating;
	int				sleeping;
}	t_philo;

int			ft_atoi(const char *str);
long long	ft_get_elapsed_time(long long start_time);
void		ft_usleep(int to_sleep);
void		init_philos(t_philo *philo, t_args args);
void		exit_err(int error);
void		manage_philosopers(t_philo *philosphers, int num);
#endif