/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:45:14 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/20 14:30:40 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_thread(t_philo *philo, t_data *data)
{
	int			i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philo);
	data->fourchette = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!philo || !data->fourchette)
		return (1);
	i = 0;
	while (i < data->nbr_philo)
		pthread_mutex_init(&data->fourchette[i++], NULL);
	pthread_mutex_init(&data->to_eat, NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].index = i;
		philo[i].s_data = data;
		philo[i].last_time_eat = ft_gettime();
		philo[i].nbr_to_eat = 0;
		i++;
	}
	data->eat = 0;
	ft_cree_thread_norm(philo);
	return (0);
}

void	ft_cree_thread_norm(t_philo *philo)
{
	int			i;
	pthread_t	th[2];

	i = 0;
	while (i < philo->s_data->nbr_philo)
	{
		pthread_create(&philo[i].pid, NULL, &ft_routine, &philo[i]);
		i++;
	}
	pthread_create(&th[0], NULL, &check_is_dead, philo);
	if (philo->s_data->time_to_must_eat != -1)
		pthread_create(&th[1], NULL, &check_must_eat, philo);
	i = 0;
	while (i < philo->s_data->nbr_philo)
	{
		pthread_join(philo[i].pid, NULL);
		i++;
	}
	free(philo->s_data->fourchette);
	free(philo);
}

int	ft_printf(char *str, t_philo *philo)
{
	if (philo->s_data->death == 1 || philo->s_data->full == 1)
		return (1);
	printf("%llu philo %d  %s\n", (ft_gettime() - \
	philo->s_data->start_time), philo->index + 1, str);
	return (0);
}
