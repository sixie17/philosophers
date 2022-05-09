/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:48:13 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 14:52:07 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	ft_get_elapsed_time(long long start_time)
{
	long long		elapsed_time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	elapsed_time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000) - start_time;
	return(elapsed_time);
}

void	ft_usleep(int to_sleep)
{
	long long		temp_start_time;

	temp_start_time = ft_get_elapsed_time(0);
	while (1)
	{
		if (ft_get_elapsed_time(temp_start_time) >= to_sleep)
			break;
	}
}