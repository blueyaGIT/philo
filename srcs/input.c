/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:19:12 by dalbano           #+#    #+#             */
/*   Updated: 2025/05/24 13:55:54 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_input(long num_philo, long die_time, long eat_time,
		long sleep_time)
{
	if (num_philo < 0 || die_time < 0 || eat_time < 0
		|| sleep_time < 0)
	{
		printf("All values must be positive Integers\n");
		return (false);
	}
	if (num_philo < 1 || num_philo > 200)
	{
		printf("Invalid amount of philosophers\n");
		return (false);
	}
	if (die_time < 60 || eat_time < 60 || sleep_time < 60 || die_time > INT_MAX
		|| eat_time > INT_MAX || sleep_time > INT_MAX)
	{
		printf("Time values must be at least 60ms and must not exceed INT_MAX\n");
		return (false);
	}
	return (true);
}

bool	handle_input(t_data *data, char **input)
{
	data->num_philo = ft_atol(input[0]);
	data->die_time = ft_atol(input[1]);
	data->eat_time = ft_atol(input[2]);
	data->sleep_time = ft_atol(input[3]);
	if (!check_input(data->num_philo, data->die_time, data->eat_time,
			data->sleep_time))
		return (false);
	if (input[4])
	{
		data->num_meals = ft_atol(input[4]);
		if ((data->num_meals < 1 || data->num_meals > INT_MAX))
		{
			printf("Invalid number of meals\n");
			return (false);
		}
	}
	else
		data->num_meals = -1;
	return (true);
}
