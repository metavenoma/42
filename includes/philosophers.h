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
# include <threads.h>

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
}

int	args_parser(int ac, char **av);
t_args	*init_args_struct(char **av);

int	ft_atoi(const char *nptr);

#endif
