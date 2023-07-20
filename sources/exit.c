#include "philosophers.h"

int	terminate(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philosophers)
		pthread_join(args->philo[i].th, NULL);
	i = -1;
	while (++i < args->philosophers)
		pthread_mutex_destroy(&(args->forks[i]));
	pthread_mutex_destroy(&(args->write_mutex));
	pthread_mutex_destroy(&(args->last_meal_mutex));
	pthread_mutex_destroy(&(args->death_mutex));
	if (args->philo)
		free(args->philo);
	if (args->forks)
		free(args->forks);
	if (args)
		free(args);
	return(0);
}