#include "philosophers.h"

void	*philosophers_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	while (!args->is_dead)
	{
		philosophers_actions(philo, args);
		if (args->meals_finished)
			break ;
		print_philosophers(args, philo->id, "is sleeping");
		usleep(args->time_to_sleep * 1000);
		print_philosophers(args, philo->id, "is thinking");
	}
	return (NULL);
}

// int	is_philo_dead(t_args *args)
// {

// }

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
	pthread_mutex_lock(&(args->checker));
	philo->last_meal = timestamp(0);
	philo->times_ate += 1;
	pthread_mutex_unlock(&(args->checker));
	print_philosophers(args, philo->id, "is eating");
	usleep(args->time_to_eat * 1000);
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
}

void	hot_girl_watching(t_args *args)
{
	int	i;

	while (!args->meals_finished)
	{
		i = -1;
		while (++i < args->philosophers && !args->is_dead)
		{
			pthread_mutex_lock(&(args->checker));
			if (timestamp(args->philo->last_meal) > args->time_to_eat)
			{
				print_philosophers(args, args->philo->id, "died");
				args->is_dead = 1;
			}
			pthread_mutex_unlock(&(args->checker));
		}
		if (args->is_dead)
				break ;
		i = 0;
		while (i < args->philosophers && args->number_of_meals != -1)
		{
			if (args->philo->times_ate < args->number_of_meals)
				break ;
			i++;
		}
		if (i == args->philosophers)
			args->meals_finished = 1;
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		printf("\n-------------args error\n\n"); // sair do programa
	if (!args_parser(argc, argv))
		printf("\n-------------args invalid\n\n"); // sair do programa
	args = init_args(argc, argv);
	if (!args)
		return(1);
	if (init_simulation(args))
		return (1);
	return(0);
}