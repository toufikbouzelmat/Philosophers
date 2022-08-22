/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:04:03 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/22 01:16:47 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2)
		take_forks(philo);
	else
		start_thinking(philo);
	return (NULL);
}

int	ft_initialiser_struct(t_data *data, int ac, char**av)
{
	int	i;

	i = 1;
	while (ac > i)
	{
		ft_check_arg(av[i]);
		if (ft_check_arg(av[i]) == 1)
			return (1);
		i++;
	}
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->time_to_must_eat = -1;
	data->death = 0;
	data->full = 0;
	if (ac == 6)
		data->time_to_must_eat = ft_atoi(av[5]);
	data->start_time = ft_gettime();
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	t_data	data;

	if ((ac == 5) || (ac == 6))
	{
		philo.s_data = &data;
		ft_initialiser_struct(&data, ac, av);
		if (ft_check_data(&data, ac) == 0)
			ft_create_thread(&philo, &data);
	}
	return (0);
}
