/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:51:27 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 17:17:57 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * @brief Create the philo threads
 * @param core The core structure
 * @return true: The philo threads were created successfully.
 * @return false: The philo threads were not created successfully.
 * @note The philo threads are created and the philo_life function is called.
 * The node corresponding to the thread data storage is passed as an argument
 * to the philo_life function.
*/
bool	philo_creates(t_core *core)
{
	int		i;

	i = 0;
	while (i <= core->philo_count - 1)
	{
		if (pthread_create(&core->philos[i].thread, NULL, philo_life,
				&core->philos[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	philo_joins(t_core *core)
{
	int		i;

	i = 0;
	while (i <= core->philo_count - 1)
	{
		if (pthread_join(core->philos[i].thread, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	philo_table(t_core *core)
{
	if (pthread_create(&core->watcher, NULL, food_watcher, core) != 0)
		return (false);
	if (philo_creates(core) == false)
		return (false);
	if (philo_joins(core) == false)
		return (false);
	if (pthread_join(core->watcher, NULL) != 0)
		return (false);
	return (true);
}
