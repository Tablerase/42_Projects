/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:44:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/07 12:48:43 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	watcher_food_end(t_core **core)
{
	pthread_mutex_lock(&(*core)->mutex_death);
	(*core)->death = true;
	pthread_mutex_lock(&(*core)->mutex_print);
	printf("%sAll philosophers have eaten %d times%s\n", RED, \
	(*core)->meal_count, RESET);
	pthread_mutex_unlock(&(*core)->mutex_print);
	pthread_mutex_unlock(&(*core)->mutex_death);
}

static int	get_min_meal(t_core *core)
{
	int		i;
	int		min_meal;

	i = 0;
	min_meal = INT_MAX;
	while (i <= core->philo_count - 1)
	{
		pthread_mutex_lock(&core->philos[i].mutex_eat);
		if (core->philos[i].meal_eat < min_meal)
			min_meal = core->philos[i].meal_eat;
		pthread_mutex_unlock(&core->philos[i].mutex_eat);
		i++;
	}
	return (min_meal);
}

static t_philo	*philo_max_last_meal(t_core **core)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = &(*core)->philos[i];
	while (i <= (*core)->philo_count - 1)
	{
		pthread_mutex_lock(&(*core)->philos[i].mutex_eat);
		if ((get_time() - (*core)->philos[i].last_meal)
			> get_time() - philo->last_meal)
		{
			philo = &(*core)->philos[i];
		}
		pthread_mutex_unlock(&(*core)->philos[i].mutex_eat);
		i++;
	}
	return (philo);
}

static bool	watch_time_to_die(t_core *core)
{
	t_philo	*philo;

	philo = philo_max_last_meal(&core);
	pthread_mutex_lock(&philo->core->mutex_min);
	philo->core->last_meal_id = philo->id;
	pthread_mutex_unlock(&philo->core->mutex_min);
	pthread_mutex_lock(&philo->mutex_eat);
	if ((get_time() - philo->last_meal) >= (size_t)core->time_to_die + 5)
	{
		pthread_mutex_lock(&core->mutex_death);
		core->death = true;
		pthread_mutex_lock(&core->mutex_print);
		printf("%s%zu%s %d %s%s\n", GRAYB, get_time() - philo->start_time, \
REDHB, philo->id, "died", RESET);
		pthread_mutex_unlock(&core->mutex_print);
		pthread_mutex_unlock(&core->mutex_death);
		pthread_mutex_unlock(&philo->mutex_eat);
		return (false);
	}
	pthread_mutex_unlock(&philo->mutex_eat);
	return (true);
}

/**
 * @brief The food watcher function routine
 * @param arg The core structure
 * @note The watcher function is used to check if all the philosophers have
 * eaten the number of times they should. If so, the death variable is set to
 * true and the program ends.
 * @note The delay between each check is to avoid locking the mutexes too often
*/
void	*food_watcher(void *arg)
{
	t_core	*core;
	int		min_meal;

	core = (t_core *)arg;
	min_meal = 0;
	pthread_mutex_lock(&core->mutex_death);
	while (core->death == false)
	{
		pthread_mutex_unlock(&core->mutex_death);
		if (watch_time_to_die(core) == false)
			return (NULL);
		if (core->meal_count >= 1)
		{
			min_meal = get_min_meal(core);
			if (min_meal >= core->meal_count)
			{
				watcher_food_end(&core);
				return (NULL);
			}
		}
		usleep(5000);
		pthread_mutex_lock(&core->mutex_death);
	}
	pthread_mutex_unlock(&core->mutex_death);
	return (NULL);
}
