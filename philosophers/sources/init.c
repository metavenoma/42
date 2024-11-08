/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:51:20 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/03 18:11:58 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	init_philosophers(t_args *args)
{
	int	i;

	i = -1;
	args->philo = (t_philo *)malloc(sizeof(t_philo) * (args->philosophers + 1));
	while (++i < args->philosophers)
	{
		args->philo[i].id = i + 1;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->philosophers;
		args->philo[i].last_meal = 0;
		args->philo[i].times_ate = 0;
		args->philo[i].args = args;
	}
}

int	init_mutex(t_args *args)
{
	int	i;

	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (args->philosophers));
	if (args->forks)
		return (1);
	i = -1;
	while (++i < args->philosophers)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
		if (pthread_mutex_init(&(args->philo[i].is_done_mutex), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(args->write_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(args->last_meal_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(args->death_mutex), NULL))
		return (1);
	// if (pthread_mutex_init(&(args->times_ate_mutex), NULL))
	// 	return (1);
	return (0);
}

t_args	*init_args(int ac, char **av)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->philosophers = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->number_of_meals = -1;
	if (ac == 6)
		args->number_of_meals = ft_atoi(av[5]);
	args->start_time = timestamp(0);
	args->is_dead = 0;
	args->is_dead_2 = 0;
	args->meals_finished = 0;
	if (!init_mutex(args))
		return (NULL);
	init_philosophers(args);
	return (args);
}

int	init_simulation(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philosophers)
	{
		if (pthread_create(&args->philo[i].th, NULL,
				&philosophers_routine, &(args->philo[i])))
			return (1);
		pthread_mutex_lock(&(args->last_meal_mutex));
		args->philo[i].last_meal = timestamp(0);
		pthread_mutex_unlock(&(args->last_meal_mutex));
	}
	hot_girl_watching(args);
	terminate(args);
	return (0);
}
