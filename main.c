/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:22:16 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 17:04:44 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	check(t_args args)
{
	if (args.number_of_philosopher <= 0 || args.time_to_die <= 0
		|| args.time_to_eat <= 0 || args.time_to_sleep <= 0)
		exit_err(1);
}

void	parse_args(int ac, char **argv, t_args *args)
{
	args->number_of_philosopher = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	check(*args);
	if (ac == 6)
	{
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (args->number_of_times_each_philosopher_must_eat <= 0)
			exit_err(1);
	}
}

int	main(int ac, char **av)
{
	t_args		args;
	t_philo		*philosophers;

	if (ac == 5 || ac == 6)
	{
		parse_args(ac, av, &args);
		philosophers = malloc(sizeof(t_philo) * args.number_of_philosopher);
		if (!philosophers)
			return (0);
		init_philos(philosophers, args);
		manage_philosopers(philosophers, args.number_of_philosopher);
		return (0);
	}
	else if (ac < 5)
		exit_err(0);
	else
		exit_err(2);
}
