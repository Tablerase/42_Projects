/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:35:38 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/07 12:50:16 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * @brief Update the state of the philosopher
 * @param philo The philosopher structure
 * @param state The new state of the philosopher
 * @note This function is used to update the state of the philosopher. The
 * previous state is also updated.
*/
void	update_state(t_philo *philo, enum e_state state)
{
	philo->prev_state = philo->state;
	philo->state = state;
}

bool	philo_think(t_philo *philo)
{
	if (philo->state == THINKING && philo->prev_state != THINKING)
	{
		print_message(MAGB, "is thinking", philo, philo->id);
		if (wait_check(5, philo) == false)
			return (false);
		update_state(philo, THINKING);
	}
	usleep(750);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		print_message(BLUB, "is sleeping", philo, philo->id);
		if (wait_check(philo->core->time_to_sleep, philo) == false)
			return (false);
		update_state(philo, THINKING);
	}
	return (true);
}

/**
 * @brief The philosopher life routine
 * @param arg The philosopher structure
 * @note The philosopher life routine is used to simulate the life of a
 * philosopher. The philosopher will pick up the forks, eat, sleep and think.
 * The philosopher will also check if he is dead or if the death flag is set.
 * Their is a sleep in the loop becuase valgrind is not fast enough to keep up
 * and also to prevent to many 
*/
void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		wait_check(philo->core->time_to_die / 2, philo);
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_meal = get_time();
	philo->start_time = get_time();
	pthread_mutex_unlock(&philo->mutex_eat);
	while (check_death(philo->core) == false)
	{
		if (philo_eat(philo) == false)
			return (NULL);
		if (philo_sleep(philo) == false)
			return (NULL);
		philo_think(philo);
		usleep(750);
	}
	return (NULL);
}
