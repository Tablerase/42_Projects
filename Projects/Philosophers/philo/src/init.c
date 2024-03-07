/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:36:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 14:46:13 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

bool	init_forks(t_core *core)
{
	int		i;

	core->forks = NULL;
	core->forks = malloc(sizeof(t_fork) * core->philo_count);
	if (core->forks == NULL)
	{
		free(core->philos);
		return (false);
	}
	i = 0;
	while (i < core->philo_count)
	{
		core->forks[i].id = i + 1;
		core->forks[i].user = AVAILABLE;
		if (pthread_mutex_init(&core->forks[i].mutex_fork, NULL) != 0 || \
		pthread_mutex_init(&core->forks[i].mutex_usage, NULL) != 0)
		{
			free(core->philos);
			free(core->forks);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_philos_forks(t_core *core)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < core->philo_count)
	{
		philo = &core->philos[i];
		philo->left_fork = &core->forks[i];
		if (philo->id == core->philo_count)
			philo->right_fork = &core->forks[0];
		else
			philo->right_fork = &core->forks[i + 1];
		i++;
	}
	return (true);
}

bool	init_philos(t_core **core)
{
	int		i;

	(*core)->philos = malloc(sizeof(t_philo) * (*core)->philo_count);
	if ((*core)->philos == NULL)
		return (false);
	i = 0;
	while (i <= (*core)->philo_count - 1)
	{
		(*core)->philos[i].id = i + 1;
		(*core)->philos[i].core = *core;
		(*core)->philos[i].start_time = get_time();
		(*core)->philos[i].last_meal = get_time();
		(*core)->philos[i].meal_eat = 0;
		(*core)->philos[i].state = INIT;
		(*core)->philos[i].prev_state = INIT;
		if (pthread_mutex_init(&(*core)->philos[i].mutex_eat, NULL) != 0)
		{
			free((*core)->philos);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_core(t_core *core)
{
	core->start_time = get_time();
	if (init_philos(&core) == false)
		return (false);
	if (init_forks(core) == false)
		return (false);
	if (init_philos_forks(core) == false)
		return (false);
	return (true);
}
