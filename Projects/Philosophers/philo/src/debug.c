/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:25:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/03/05 18:12:27 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	print_core(t_core *core)
{
	printf("==================== %sCORE%s ====================\n", BGRN, RESET);
	printf("philo_count: %d 🧑\n", core->philo_count);
	printf("time_to_die: %d 💀\n", core->time_to_die);
	printf("time_to_eat: %d 🍔\n", core->time_to_eat);
	printf("time_to_sleep: %d 💤\n", core->time_to_sleep);
	printf("meal_count: %d 🍴\n", core->meal_count);
	printf("==============================================\n");
}

// static char	*get_usage(enum e_usage usage)
// {
// 	if (usage == AVAILABLE)
// 		return ("AVAILABLE");
// 	else if (usage == USED)
// 		return ("USED");
// 	else
// 		return ("UNKNOWN");
// }

void	print_forks(t_core *core)
{
	int		i;

	printf("=================== %sFORKS%s ===================\n", BYEL, RESET);
	i = 0;
	while (i <= core->philo_count - 1)
	{
		printf("%sFork %d%s: %d\n", YEL, core->forks[i].id, RESET, \
core->forks[i].user);
		printf("mutex_fork: %p\n", &core->forks[i].mutex_fork);
		i++;
	}
	printf("==============================================\n");
}

void	print_philos(t_core *core)
{
	int		i;

	printf("================== %sPHILOS%s ===================\n", BCYN, RESET);
	i = 0;
	while (i <= (core)->philo_count - 1)
	{
		printf("----------------------------------------------\n");
		printf("%sPhilo %d%s\n", CYN, (core)->philos[i].id, RESET);
		printf("last_meal: %ld\n", (core)->philos[i].last_meal);
		printf("meal_eat: %d\n", (core)->philos[i].meal_eat);
		i++;
	}
	printf("==============================================\n");
}

// static char	*get_state(enum e_state state)
// {
// 	if (state == THINKING)
// 		return ("THINKING");
// 	else if (state == EATING)
// 		return ("EATING");
// 	else if (state == SLEEPING)
// 		return ("SLEEPING");
// 	else if (state == DEAD)
// 		return ("DEAD");
// 	else
// 		return ("UNKNOWN");
// }
