/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 06:12:22 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/14 17:33:19 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_erreur(void)
{
	write(1, "invalid argument!!\n", 20);
	return (0);
}

long long	ft_gettime(void)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_sleep(int time)
{
	long long	beg;

	beg = ft_gettime();
	while (ft_gettime() - beg < time)
	{
		usleep(500);
	}
}
