/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:45:26 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/01 14:37:51 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/**
 * @brief Initializes the table structure for the dining philosophers simulation
 * 
 * This function sets up the central control unit (table) that manages the
 * dining philosophers simulation. It zeros out the table structure, assigns
 * the configuration data, and initializes all necessary mutexes for thread
 * synchronization.
 * 
 * Initialized mutexes:
 * - table_data_mutex: Protects access to shared table data
 * - simulation_mutex: Controls simulation state changes
 * - start_time_mutex: Synchronizes access to simulation start time
 * - print_mutex: Ensures atomic printing operations
 * 
 * @param table Pointer to the table structure to be initialized
 * @param data Pointer to the configuration data containing simulation parameters
 * @return true if all mutexes were successfully created, false otherwise
 * 
 * @note If any mutex creation fails, the function returns false and the
 *       caller should handle cleanup and error reporting
 */
bool table_init(t_table *table, t_data *data)
{
	memset(table, 0, sizeof(t_table));
	table->data = data;
	table->monitor_thread_created = true;
	if (!create_mutex(&table->table_data_mutex))
		return (false);
	if (!create_mutex(&table->simulation_mutex))
		return (false);
	if (!create_mutex(&table->start_time_mutex))
		return (false);
	if (!create_mutex(&table->print_mutex))
		return (false);
	return (true);
}
