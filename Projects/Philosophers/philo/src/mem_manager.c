/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:05:31 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/06 17:27:19 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	free_forks(t_core *core)
{
	int		i;

	i = 0;
	while (i <= core->philo_count - 1)
	{
		pthread_mutex_destroy(&core->forks[i].mutex_fork);
		pthread_mutex_destroy(&core->forks[i].mutex_usage);
		i++;
	}
	free(core->forks);
}

static void	free_philos(t_core *core)
{
	int		i;

	i = 0;
	while (i <= core->philo_count - 1)
	{
		pthread_mutex_destroy(&core->philos[i].mutex_eat);
		i++;
	}
	free(core->philos);
}

void	free_core(t_core *core)
{
	if (core == NULL)
		return ;
	pthread_mutex_destroy(&core->mutex_death);
	pthread_mutex_destroy(&core->mutex_print);
	if (core->forks != NULL)
		free_forks(core);
	if (core->philos != NULL)
		free_philos(core);
}
