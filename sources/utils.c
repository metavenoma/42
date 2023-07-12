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

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_diff(long long previous_time)
{
	long long	current_time;

	current_time = timestamp();
	return(current_time - previous_time);
}

void	ft_usleep(long long time)
{
	long long	current_time;

	current_time = timestamp();
	while (timestamp() - current_time < time)
		usleep(50);
}

void	print_philosophers(t_args *args, int philo_id, char *s)
{
	pthread_mutex_lock(&(args->write_mutex));
	printf("%lli ", time_diff(args->start_time));
	printf("%i ", philo_id);
	printf("%s\n", s);
	pthread_mutex_unlock(&(args->write_mutex));
}