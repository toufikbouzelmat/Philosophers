/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:34:55 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/18 23:31:31 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->index % 2 != 0)
	{
		pthread_mutex_lock(&philo->s_data->fourchette[(philo->index + 1) % \
		philo->s_data->nbr_philo]);
		if (ft_printf("has taken a fork", philo))
			return ;
		pthread_mutex_lock(&philo->s_data->fourchette[philo->index]);
		if (ft_printf("has taken a fork", philo))
			return ;
	}
	else if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->s_data->fourchette[philo->index]);
		if (ft_printf("has taken a fork", philo))
			return ;
		pthread_mutex_lock(&philo->s_data->fourchette[(philo->index + 1) % \
		philo->s_data->nbr_philo]);
		if (ft_printf("has taken a fork", philo))
			return ;
	}
	start_eating(philo);
}

void	start_eating(t_philo *philo)
{
	if (ft_printf("is eating", philo))
		return ;
	philo->nbr_to_eat++;
	if (philo->nbr_to_eat == philo->s_data->time_to_must_eat)
	{
		pthread_mutex_lock(&philo->s_data->to_eat);
		philo->s_data->eat++;
		pthread_mutex_unlock(&philo->s_data->to_eat);
	}
	philo->last_time_eat = ft_gettime();
	ft_sleep(philo->s_data->time_to_eat);
	pthread_mutex_unlock(&philo->s_data->fourchette[philo->index]);
	pthread_mutex_unlock(&philo->s_data->fourchette[(philo->index + 1) % \
	philo->s_data->nbr_philo]);
	start_sleeping(philo);
}

void	start_sleeping(t_philo *philo)
{
	if (ft_printf("is sleeping", philo))
		return ;
	ft_sleep(philo->s_data->time_to_sleep);
	start_thinking(philo);
}

void	start_thinking(t_philo *philo)
{
	if (ft_printf("is thinking", philo))
		return ;
	usleep(500);
	take_forks(philo);
}
