/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:51:22 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/08/19 15:21:48 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_must_eat;
	int					nbr_philo;
	long long			start_time;
	int					death;
	int					full;
	int					eat;
	pthread_mutex_t		*fourchette;
	pthread_mutex_t		to_eat;
}	t_data;

typedef struct s_philo
{
	t_data			*s_data;
	int				index;
	int				nbr_to_eat;
	long long		last_time_eat;
	pthread_t		pid;
}	t_philo;

int			ft_isdigit(int n);
int			ft_atoi(char *str);
int			ft_check_data(t_data *data, int ac);
int			ft_erreur(void);
int			ft_check_arg(char *str);
int			ft_create_thread(t_philo *philo, t_data *data);
void		*ft_thread1(void *arg);
void		*ft_routine(void *arg);
long long	ft_gettime(void);
int			ft_initialiser_struct(t_data *data, int ac, char**av);
void		ft_sleep(int time);
int			ft_printf(char *str, t_philo *philo);
void		*check_is_dead(void *check);
void		take_forks(t_philo *philo);
void		start_eating(t_philo *philo);
void		start_sleeping(t_philo *philo);
void		start_thinking(t_philo *philo);
int			ft_norm(t_data *data, t_philo *philo);
void		ft_norm2(t_philo *philo);
void		ft_norm3(int i, t_philo *philo);
void		*check_must_eat(void *check);
void		ft_cree_thread_norm(t_philo *philo);

#endif