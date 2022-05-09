/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:48:13 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 16:53:28 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	time_passed(long long start_time)
{
	long long		elapsed_time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	elapsed_time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000) - start_time;
	return (elapsed_time);
}
