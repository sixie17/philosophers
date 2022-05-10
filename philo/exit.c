/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:26:09 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/09 17:04:52 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	exit_err(int error)
{
	if (error == 0)
		write (2, "Not Enough Arguments\n", 22);
	if (error == 1)
		write(2, "positive numbers only\n", 23);
	if (error == 2)
		write(2, "Too many arguments\n", 20);
	exit(0);
}
