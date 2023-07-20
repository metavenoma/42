/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:43:35 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/20 20:43:41 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosophers_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	while (1)
	{
		if (has_anyone_died(args))
			break ;
		// pthread_mutex_lock(&(args->last_meal_mutex));
		if (args->number_of_meals != -1
			&& philo->times_ate >= args->number_of_meals)
		{
			// pthread_mutex_unlock(&(args->last_meal_mutex));
			break ;
		}
		// pthread_mutex_unlock(&(args->last_meal_mutex));
		philosophers_actions(philo, args);
		print_philosophers(args, philo->id, "is sleeping");
		usleep(args->time_to_sleep * 1000);
		print_philosophers(args, philo->id, "is thinking");
		if (philo->id % 2)
			usleep(200);
	}
	return (NULL);
}

int	has_anyone_died(t_args *args)
{
	pthread_mutex_lock(&(args->death_mutex));
	if (args->is_dead_2)
	{
		pthread_mutex_unlock(&(args->death_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(args->death_mutex));
	return (0);
}

void	philosophers_actions(t_philo *philo, t_args *args)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&(args->forks[philo->left_fork]));
		print_philosophers(args, philo->id, "has taken a fork");
		pthread_mutex_lock(&(args->forks[philo->right_fork]));
		print_philosophers(args, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(args->forks[philo->right_fork]));
		print_philosophers(args, philo->id, "has taken a fork");
		pthread_mutex_lock(&(args->forks[philo->left_fork]));
		print_philosophers(args, philo->id, "has taken a fork");
	}
	pthread_mutex_lock(&(args->last_meal_mutex));
	philo->last_meal = timestamp(0);
	pthread_mutex_unlock(&(args->last_meal_mutex));
	pthread_mutex_lock(&(args->times_ate_mutex));
	philo->times_ate += 1;
	pthread_mutex_unlock(&(args->times_ate_mutex));
	print_philosophers(args, philo->id, "is eating");
	usleep(args->time_to_eat * 1000);
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
}

int	is_dinner_finished(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->times_ate_mutex));
	if (philo->times_ate < args->number_of_meals || args->number_of_meals == -1)
	{
		pthread_mutex_unlock(&(args->times_ate_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(args->times_ate_mutex));
	return (1);
}

int	is_philo_dead(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->last_meal_mutex));
	if (timestamp(philo->last_meal) > args->time_to_die)
	{
		pthread_mutex_unlock(&(args->last_meal_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(args->last_meal_mutex));
	return (0);
}

void	hot_girl_watching(t_args *args)
{
	int	i;
	int	philosophers_ate;

	while (1)
	{
		i = -1;
		philosophers_ate = 0;
		while (++i < args->philosophers)
		{
			if (is_philo_dead(args, &args->philo[i])
				&& !is_dinner_finished(args, &args->philo[i]))
			{
				print_philosophers(args, args->philo[i].id, "died");
				args->is_dead = 1;
			}
			pthread_mutex_lock(&(args->times_ate_mutex));
			if (args->philo[i].times_ate >= args->number_of_meals
				&& args->number_of_meals != -1)
				philosophers_ate++;
			pthread_mutex_unlock(&(args->times_ate_mutex));
		}
		if (args->is_dead)
		{
			pthread_mutex_lock(&(args->death_mutex));
			args->is_dead_2 = 1;
			pthread_mutex_unlock(&(args->death_mutex));
			break ;
		}
		if (philosophers_ate == args->philosophers)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		return (1);
	if (!args_parser(argc, argv))
		return (1);
	args = init_args(argc, argv);
	if (!args)
		return (1);
	if (init_simulation(args))
		return (1);
	return(0);
}
