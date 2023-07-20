/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:01:00 by rverona-          #+#    #+#             */
/*   Updated: 2023/07/11 15:50:08 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args t_args;

typedef struct s_philo {
	int			id;
	pthread_t 	th;
	int			left_fork;
	int			right_fork;
	long long	last_meal;
	int			times_ate;
	t_args		*args;
}	t_philo;

typedef struct s_args {
	int				philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				is_dead;
	int				is_dead_2;
	int				meals_finished;
	long long		start_time;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t times_ate_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t *forks;
	t_philo			*philo;
}	t_args;

int			args_parser(int ac, char **av);
void		init_philosophers(t_args *args);
t_args		*init_args(int ac, char **av);
void		*philosophers_routine(void *arg);
void		init_forks(t_args *args);
int			init_simulation(t_args *args);
int			terminate(t_args *args);
long long	timestamp(long long previous_time);
void		print_philosophers(t_args *args, int philo_id, char *s);
void		philosophers_actions(t_philo *philo, t_args *args);
void		hot_girl_watching(t_args *args);
int			has_anyone_died(t_args *args);

int		is_philo_dead(t_args *args, t_philo *philo);
int		is_dinner_finished(t_args *args, t_philo *philo);

int			ft_atoi(const char *nptr);

#endif
