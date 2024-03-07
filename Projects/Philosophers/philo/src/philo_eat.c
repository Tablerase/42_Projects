/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:03 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/07 12:28:29 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	single_philo(t_philo *philo)
{
	print_message(YELB, "has taken a fork", philo, philo->id);
	philo_think(philo);
	wait_for(philo->core->time_to_die);
	wait_check(20, philo);
}

static void	no_available_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex_fork);
	philo->left_fork->user = AVAILABLE;
	pthread_mutex_unlock(&philo->left_fork->mutex_fork);
	update_state(philo, THINKING);
}

static void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->core->mutex_forks);
	pthread_mutex_lock(&philo->left_fork->mutex_fork);
	if (philo->left_fork->user == AVAILABLE)
	{
		philo->left_fork->user = philo->id;
		pthread_mutex_unlock(&philo->left_fork->mutex_fork);
		pthread_mutex_lock(&philo->right_fork->mutex_fork);
		if (philo->right_fork->user == AVAILABLE)
		{
			philo->right_fork->user = philo->id;
			pthread_mutex_unlock(&philo->right_fork->mutex_fork);
			update_state(philo, EATING);
		}
		else
		{
			pthread_mutex_unlock(&philo->right_fork->mutex_fork);
			no_available_forks(philo);
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->left_fork->mutex_fork);
		update_state(philo, THINKING);
	}
	pthread_mutex_unlock(&philo->core->mutex_forks);
}

bool	philo_eat(t_philo *philo)
{
	if (philo->core->philo_count == 1)
	{
		single_philo(philo);
		return (false);
	}
	pick_forks(philo);
	if (philo->state == EATING)
	{
		print_message(YELB, "has taken a fork", philo, philo->id);
		print_message(YELB, "has taken a fork", philo, philo->id);
		print_message(GRNB, "is eating", philo, philo->id);
		pthread_mutex_lock(&philo->mutex_eat);
		philo->last_meal = get_time();
		philo->meal_eat += 1;
		pthread_mutex_unlock(&philo->mutex_eat);
		if (wait_check(philo->core->time_to_eat, philo) == false)
			return (false);
		update_state(philo, SLEEPING);
		pthread_mutex_lock(&philo->core->mutex_forks);
		philo->left_fork->user = AVAILABLE;
		philo->right_fork->user = AVAILABLE;
		pthread_mutex_unlock(&philo->core->mutex_forks);
	}
	return (true);
}
