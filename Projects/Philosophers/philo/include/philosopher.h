/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:28:34 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 19:07:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

// Standard Libs
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// Limits
# include <limits.h>
// Boolean
# include <stdbool.h>
// Time
# include <sys/time.h>
// Threads
# include <pthread.h>
// Colors
# include "color.h"

// Structures

/**
 * @brief The state of the philosopher
 * @param THINKING The philosopher is thinking when not eating or sleeping
 * @param EATING The philosopher is eating
 * @param SLEEPING The philosopher is sleeping
 * @param DEAD The philosopher is dead
*/
enum e_state
{
	INIT,
	THINKING,
	EATING,
	SLEEPING	
};

/**
 * @brief The usage of the fork
 * @param AVAILABLE The fork is available
 * @param USED The fork is used
*/
enum e_usage
{
	AVAILABLE,
	USED
};

/**
 * @brief The fork structure
 * @param id The id of the fork
 * @param usage The usage of the fork
 * @param mutex The mutex of the fork
*/
typedef struct s_fork
{
	int				id;

	int				user;
	pthread_mutex_t	mutex_usage;

	pthread_mutex_t	mutex_fork;
}	t_fork;

typedef struct s_core	t_core;

/**
 * @brief The philosopher structure
 * @param id The id of the philosopher
 * @param start_time The start time of the philosopher
 * @param meal_eat The number of meals eaten
 * @param last_meal The last time the philosopher ate (in microseconds)
 * @param mutex_eat The mutex for the meal_eat and last_meal
 * @param core The core structure
 * @param thread The thread of the philosopher
 * @param left_fork The left fork of the philosopher
 * @param right_fork The right fork of the philosopher
*/
typedef struct s_philo
{
	int				id;
	size_t			start_time;
	enum e_state	state;
	enum e_state	prev_state;

	int				meal_eat;
	size_t			last_meal;
	pthread_mutex_t	mutex_eat;

	t_core			*core;
	pthread_t		thread;

	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

/**
 * @brief The core structure of the program
 * @param philo_count The number of philosophers
 * @param time_to_die The time to die
 * @param time_to_eat The time to eat
 * @param time_to_sleep The time to sleep
 * @param meal_count The number of meals needed to be eaten
 * @param start_time The start time of the program
 * @param death The death state of the program
 * @param mutex_death The mutex for the death state
 * @param mutex_print The mutex for the print
 * @param philos The philosophers array
*/
struct s_core
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_count;

	int				time_to_think;

	int				last_meal_id;
	pthread_mutex_t	mutex_min;

	size_t			start_time;
	bool			death;
	pthread_mutex_t	mutex_forks;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_print;

	pthread_t		watcher;
	t_philo			*philos;
	t_fork			*forks;
};

// Parsing

size_t	ft_strlen(const char *s);
bool	ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

bool	check_args(int argc, char **argv);
bool	parse_args(t_core *core, int argc, char **argv);

// Initialization

bool	init_core(t_core *core);

// Philosophers

bool	philo_table(t_core *core);

// Philosophers Life

void	*philo_life(void *arg);
bool	check_death(t_core *core);

// Philosophers Actions

void	update_state(t_philo *philo, enum e_state state);
bool	philo_eat(t_philo *philo);

bool	philo_think(t_philo *philo);
bool	philo_sleep(t_philo *philo);

// Watcher

void	*food_watcher(void *arg);

// Time

size_t	get_time(void);
void	wait_for(size_t time);
bool	wait_check(size_t time, t_philo *philo);

// Free

void	free_core(t_core *core);

// Debug

void	print_core(t_core *core);
void	print_forks(t_core *core);
void	print_philos(t_core *core);

void	print_message(char *color, char *str, t_philo *philo, int id);

#endif