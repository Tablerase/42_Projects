/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:26:48 by rcutte            #+#    #+#             */
/*   Updated: 2024/02/29 22:29:04 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	debug_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->core->mutex_print);
	printf("%s\n", message);
	pthread_mutex_unlock(&philo->core->mutex_print);
}
