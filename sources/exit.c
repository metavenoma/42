#include "philosophers.h"

int	terminate(t_args *args)
{
	if (args->philo)
		free(args->philo);
	if (args->forks)
		free(args->forks);
	if (args)
		free(args);
	return(0);
}