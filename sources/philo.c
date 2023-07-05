/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:51:20 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/03 18:11:58 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	args_parser(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_philo	*init_philosophers(int ac, char **av)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->args = (t_args *)malloc(sizeof(t_args));
	if (!philo || !philo->args)
		return (NULL);
	philo->args->philosophers = ft_atoi(av[1]);
	philo->args->time_to_die = ft_atoi(av[2]);
	philo->args->time_to_eat = ft_atoi(av[3]);
	philo->args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->args->number_of_meals = ft_atoi(av[5]);
	else
		philo->args->number_of_meals = 0;
	init_forks(philo);
	return (philo);
}

void	*philosophers_routine(void *arg)
{
	printf("hello from thread");
	return (arg);
}

void	init_forks(t_philo *philo)
{
	int	i;

	philo->forks = (int *)malloc((sizeof(int) *
			philo->args->philosophers));
	philo->th = (pthread_t *)malloc((sizeof(pthread_t) *
				philo->args->philosophers));
	if (!philo->forks || !philo->th)
		return ;
	i = -1;
	while (++i < philo->args->philosophers)
	{
		philo->forks[i] = 1;
		philo->th[i] = 0;
	}
}

void	init_simulation(t_philo *philo)
{
	int	i;

	i = -1;
	while (i < philo->args->philosophers)
		pthread_create(&philo->th[i], NULL, &philosophers_routine, NULL);
	i = -1;
	while (i < philo->args->philosophers)
		pthread_join(philo->th[i], NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if (argc < 5 || argc > 6)
		printf("\n-------------args error\n\n"); // sair do programa
	if (!args_parser(argc, argv))
		printf("\n-------------args invalid\n\n"); // sair do programa
	philo = init_philosophers(argc, argv);
	(void)philo;
	return(0);
}
