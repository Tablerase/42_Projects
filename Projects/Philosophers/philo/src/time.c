/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:46:11 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/07 12:47:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * @brief Get the current time in milliseconds
 * @return The current time in milliseconds
 * @note The time is calculated by multiplying the seconds by 1000 and adding
 * the microseconds divided by 1000 to get the milliseconds.
 * @note It allows to get the time in milliseconds with the seconds
 * since the epoch
 * @note Epoch time is the time that has passed since 00:00:00 Coordinated
 * Universal Time (UTC), Thursday, 1 January 1970.
*/
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief Wait for a certain amount of time
 * @param time The time to wait in milliseconds
 * @note The function uses the usleep function to wait for the given time
 * @note The usleep function is used to suspend the execution of the calling
 * thread for (at least) usec microseconds
*/
void	wait_for(size_t time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

/**
 * @brief Wait for a certain amount of time and check
 * if the philosopher is dead or if the death flag is set
 * @param time The time to wait in milliseconds
 * @param philo The philosopher to check
 * @return true if the philosopher/philosophers are not dead before time,
 * false otherwise
*/
bool	wait_check(size_t time, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_death(philo->core) == true)
			return (false);
		usleep(500);
	}
	return (true);
}

void	print_message(char *color, char *str, t_philo *philo, int id)
{
	size_t	time;

	time = get_time() - philo->core->start_time;
	if (check_death(philo->core) == true)
		return ;
	pthread_mutex_lock(&philo->core->mutex_print);
	printf("%s%zu%s %d %s%s\n", GRAYB, time, color, id, str, RESET);
	pthread_mutex_unlock(&philo->core->mutex_print);
}
