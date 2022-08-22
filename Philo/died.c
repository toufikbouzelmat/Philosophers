/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:28:04 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/19 17:22:17 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_is_dead(void *check)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)check;
	i = 0;
	ft_norm3(i, philo);
	return (NULL);
}

void	ft_norm2(t_philo *philo)
{
	int	j;

	j = 0;
	while (j < philo->s_data->nbr_philo)
	{
		pthread_mutex_unlock(&philo->s_data->fourchette[j]);
		j++;
	}
}

void	ft_norm3(int i, t_philo *philo)
{
	while (i < philo->s_data->nbr_philo && !philo->s_data->full)
	{
		if (ft_gettime() - philo[i].last_time_eat > philo->s_data->time_to_die)
		{
			philo->s_data->death = 1;
			printf("%llu philo %d died\n", ft_gettime()
				- philo->s_data->start_time, philo[i].index + 1);
			ft_norm2(philo);
			break ;
		}
		i++;
		if (i == philo->s_data->nbr_philo)
			i = 0;
	}
}

void	*check_must_eat(void *check)
{
	t_philo		*philo;
	int			i;
	int			eat;

	eat = 0;
	philo = (t_philo *)check;
	i = 0;
	while (!philo->s_data->death && \
	philo->s_data->eat < philo->s_data->nbr_philo)
		;
	philo->s_data->full = 1;
	ft_norm2(philo);
	return (NULL);
}
