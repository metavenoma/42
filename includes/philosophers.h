/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:01:00 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/03 18:12:02 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_args {
	int	philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
}	t_args;

typedef struct s_philo {
	t_args		*args;
	pthread_t 	*th;
	int		*forks;
}	t_philo;

int	args_parser(int ac, char **av);
t_philo	*init_philosophers(int ac, char **av);
void	*philosophers_routine(void *arg);
void	init_forks(t_philo *philo);

int	ft_atoi(const char *nptr);

#endif
