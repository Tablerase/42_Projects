/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:36 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 17:17:44 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * @brief Check if the philosopher is dead or if the death flag is set
 * @param core The core structure
 * @return true if the philosopher is dead, false otherwise
*/
bool	check_death(t_core *core)
{
	pthread_mutex_lock(&core->mutex_death);
	if (core->death == true)
	{
		pthread_mutex_unlock(&core->mutex_death);
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&core->mutex_death);
		return (false);
	}
}
