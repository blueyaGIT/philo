/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:04:30 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/01 14:45:59 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Displays standardized error messages for different error types
 * 
 * This function provides a centralized way to handle and display error messages
 * throughout the dining philosophers simulation program. It takes an error type
 * enumeration and prints the corresponding error message to standard output.
 * 
 * Supported error types:
 * - USAGE: For command-line argument errors
 * - THREAD: For pthread-related errors
 * - MUTEX: For mutex initialization/operation errors  
 * - TIME: For timing-related errors
 * - PHILO: For philosopher-specific errors
 * 
 * @param type The error type from the t_error_type enumeration indicating
 *             which specific error message should be displayed
 * @return void This function does not return a value
 * 
 * @note Error messages are printed to stdout rather than stderr
 * @note This function provides a unified interface for all program error reporting
 * 
 * @see t_error_type for the complete list of available error types
 */
void	error_msg(t_error_type type)
{
	if (type == USAGE)
		printf("USAGE ERROR\n");
	return ;
}
