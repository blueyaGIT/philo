/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:45:26 by dalbano           #+#    #+#             */
/*   Updated: 2025/05/24 14:08:09 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
