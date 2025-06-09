/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:07:16 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/09 14:12:31 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(pthread_mutex_t *mutex)
{
	int	ecode;

	if (mutex == NULL)
		return ;
	ecode = pthread_mutex_destroy(mutex);
	if (ecode == EBUSY)
		printf("Error: Mutex is still locked or in use\n");
	if (ecode == EINVAL)
		printf("Error: Mutex is invalid (not initialized or corrupted)\n");
	else if (ecode != 0)
		printf("Unknown error: %d\n", ecode);
}

void free_phils(t_philo **phils, int length)
{
	int	temp;

	temp = 0;
	while (temp < length)
	{
		free(phils[temp]);
		phils[temp] = NULL;
		temp++;
	}
	free(phils);
}

void	kill_all_mutex(t_table *table, long length)
{
	t_philo	*philo;
	int		temp;

	temp = 0;
	while (temp < length)
	{
		philo = table->philos[temp];
		if (philo->philo_thread_created)
		{
			destroy_mutex(&philo->philo_mutex);
			destroy_mutex(&philo->philo_full_mutex);
			destroy_mutex(&philo->l_fork_mutex);
			destroy_mutex(&philo->last_meal_time_mutex);
		}
		temp++;
	}
	if (table->monitor_thread_created)
	{
		destroy_mutex(&table->print_mutex);
		destroy_mutex(&table->table_data_mutex);
		destroy_mutex(&table->simulation_mutex);
		destroy_mutex(&table->start_time_mutex);
	}
}
