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

t_args	*init_args_struct(char **av)
{
	t_args	*args;
	
	args = (t_args *)malloc(sizeof(t_args));
	args->philosophers = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->number_of_meals = ft_atoi(av[5]);
	else
		args->number_of_meals = 0;
	return (args);
}

void	*philosophers_routine(void *arg)
{
	
}

void	init_philosophers(t_philo *philo, t_args *args)
{
	
}

t_philo	*philosophers(t_args *args)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo));
	i = 0;
	while (i < args->philosophers)
	{
		init_philosophers(philo, args);
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;

	args = NULL;
	if (argc < 5 || argc > 6)
		printf("\n-------------args error\n\n"); // sair do programa
	if (!args_parser(argc, argv))
		printf("\n-------------args invalid\n\n"); // sair do programa
	args = init_args_struct(argv);
	return(0);
}
