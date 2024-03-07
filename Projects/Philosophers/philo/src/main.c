/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 17:27:06 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * TODO:
 * - Handle eating process
 * - Handle odd number - add priority system
 * - Handle death
 * - Handle times
 * 		- check for death every 10ms (during eating, sleeping, thinking)
 * 			- if death, print death message and return
 * 			- while loop for duration with usleep iterations of 10ms
 * - Handle sleeping
 * - Handle printing
*/

static t_core	*init_core_values(t_core *new_core)
{
	new_core->philo_count = 0;
	new_core->time_to_die = 0;
	new_core->time_to_eat = 0;
	new_core->time_to_sleep = 0;
	new_core->time_to_think = 5;
	new_core->meal_count = 0;
	new_core->last_meal_id = 0;
	new_core->death = false;
	new_core->start_time = 0;
	new_core->forks = NULL;
	new_core->philos = NULL;
	pthread_mutex_init(&new_core->mutex_death, NULL);
	pthread_mutex_init(&new_core->mutex_print, NULL);
	pthread_mutex_init(&new_core->mutex_forks, NULL);
	pthread_mutex_init(&new_core->mutex_min, NULL);
	return (new_core);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (check_args(argc, argv) == false)
		return (EXIT_FAILURE);
	init_core_values(&core);
	if (parse_args(&core, argc, argv) == false)
		return (EXIT_FAILURE);
	if (init_core(&core) == false)
		return (EXIT_FAILURE);
	if (philo_table(&core) == false)
		return (free_core(&core), EXIT_FAILURE);
	free_core(&core);
	return (EXIT_SUCCESS);
}
