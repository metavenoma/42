/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:25:21 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/03 17:26:01 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	res;
	int	i;

	signal = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (nptr[i] - 48);
		i++;
	}
	return (res * signal);
}

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

long long	timestamp(long long previous_time)
{
	long long		current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return(current_time - previous_time);
}

void	print_philosophers(t_args *args, int philo_id, char *s)
{
	pthread_mutex_lock(&(args->write_mutex));
	if (!args->is_dead)
	{
		printf("%lli ", timestamp(args->start_time));
		printf("%i ", philo_id);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(args->write_mutex));
}