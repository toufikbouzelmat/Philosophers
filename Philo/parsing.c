/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 07:18:32 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/19 15:27:53 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' )
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (n);
	}
	return (0);
}

int	ft_check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_data(t_data *data, int ac)
{
	if ((ac == 5) && (data->nbr_philo <= 0 || data->time_to_die <= 0 \
	|| data->time_to_eat <= 0 || data->time_to_sleep <= 0))
		return (1);
	if ((ac == 6) && (data->nbr_philo <= 0 || data->time_to_die <= 0 \
	|| data->time_to_eat <= 0 || data->time_to_sleep <= 0 \
	|| data->time_to_must_eat <= 0))
		return (1);
	return (0);
}
