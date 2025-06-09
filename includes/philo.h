/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:52:11 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/09 14:12:05 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* LIBRARIES */
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* INCLUDES */

# define TEST printf

# define FORK "has taken a fork"
# define L_FORK "has taken a left fork"
# define R_FORK "has taken a right fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

/* STRUCTS */
typedef struct s_data
{
	long			num_philo;
	long			num_meals;
	long			die_time;
	long			eat_time;
	long			sleep_time;
}					t_data;

typedef struct s_table
{
	t_data			*data;
	bool			monitor_thread_created;
	long			start_time;
	long			num_threads_running;
	bool			simulation_start;
	bool			simulation_finished;
	pthread_t		monitor;
	struct s_philo	**philos;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	table_data_mutex;
	pthread_mutex_t	simulation_mutex;
	pthread_mutex_t	start_time_mutex;
}					t_table;

typedef struct s_philo
{
	t_table			*table;
	int				id;
	long			last_meal_time;
	long			meals_eaten;
	bool			full;
	bool			philo_thread_created;
	pthread_t		thread;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	philo_full_mutex;
	pthread_mutex_t	last_meal_time_mutex;
	pthread_mutex_t	l_fork_mutex;
	pthread_mutex_t	*r_fork_mutex;
}					t_philo;

typedef enum e_error_type
{
	USAGE,
	THREAD,
	MUTEX,
	TIME,
	PHILO,
	PHILO_MALLOC
}					t_error_type;

/* FUNCS */
bool				handle_input(t_data *data, char **input);
t_philo				**philos_init(t_table *table);
bool				table_init(t_table *table, t_data *data);

/* HELPER FUNCS */
long				ft_atol(const char *str);
bool				create_mutex(pthread_mutex_t *mutex);
void				error_msg(t_error_type type);
void				free_phils(t_philo **phils, int length);
void				kill_all_mutex(t_table *table, long length);
void				destroy_mutex(pthread_mutex_t *mutex);

#endif /* PHILO_H */