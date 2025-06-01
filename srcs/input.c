/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:19:12 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/01 14:39:15 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Validates the core simulation parameters for the dining philosophers problem
 * 
 * This function performs comprehensive validation of the essential simulation parameters
 * to ensure they meet the requirements for a valid dining philosophers simulation.
 * It checks for proper ranges, minimum timing constraints, and maximum value limits.
 * 
 * Validation rules:
 * - All values must be non-negative
 * - Number of philosophers: 1-200 (inclusive)
 * - Time values: minimum 60ms, maximum INT_MAX
 * 
 * @param num_philo Number of philosophers participating in the simulation
 * @param die_time Maximum time (in milliseconds) a philosopher can go without eating
 * @param eat_time Time (in milliseconds) it takes for a philosopher to eat
 * @param sleep_time Time (in milliseconds) a philosopher spends sleeping
 * @return true if all parameters are valid, false otherwise
 * 
 * @note This function prints specific error messages to stdout when validation fails
 * @note The 60ms minimum for time values ensures the simulation runs at a reasonable pace
 */
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

/**
 * @brief Parses and validates command-line arguments for the dining philosophers simulation
 * 
 * This function processes the command-line arguments provided to the program, converts
 * them from strings to appropriate numerical values, and validates their correctness.
 * It handles both mandatory parameters (philosopher count and timing values) and
 * the optional number of meals parameter.
 * 
 * Expected input format:
 * - input[0]: number_of_philosophers (1-200)
 * - input[1]: time_to_die (≥60ms, ≤INT_MAX)
 * - input[2]: time_to_eat (≥60ms, ≤INT_MAX)
 * - input[3]: time_to_sleep (≥60ms, ≤INT_MAX)
 * - input[4]: [optional] number_of_times_each_philosopher_must_eat (≥1, ≤INT_MAX)
 * 
 * @param data Pointer to the data structure to be populated with parsed values
 * @param input Array of string arguments from command line (starting from argv[1])
 * @return true if all inputs are successfully parsed and validated, false otherwise
 * 
 * @note If input[4] is not provided, num_meals is set to -1 (unlimited meals)
 * @note The function uses ft_atol() for string-to-long conversion
 * @note Prints specific error messages for different validation failures
 */
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
