/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:59:05 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/03 10:36:56 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Creates and initializes a
 * pthread mutex with default attributes
 * 
 * This function safely initializes a pthread mutex using the standard
 * pthread_mutex_init() function with default attributes (NULL). It provides
 * error handling and feedback for mutex creation failures, which is crucial
 * for the dining philosophers simulation where mutexes are essential for
 * thread synchronization and preventing race conditions.
 * 
 * The function follows a defensive programming approach by:
 * - Checking the return value of pthread_mutex_init()
 * - Providing user feedback on failure
 * - Setting the mutex pointer to NULL on failure
 * (though this may not be effective)
 * - Returning a clear success/failure indication
 * 
 * @param mutex Pointer to the pthread_mutex_t structure to be initialized
 * @return true if the mutex was successfully initialized, false on failure
 * 
 * @note The mutex pointer is set to NULL on failure, but this assignment
 *       affects only the local copy of the pointer, not the original
 * @note This function prints an error message to stdout if initialization fails
 * @note The caller should check the return value
 * and handle failures appropriately
 * @warning Ensure the mutex pointer is valid before calling this function
 * 
 * @see pthread_mutex_init(3) for details on mutex initialization
 * @see pthread_mutex_destroy() for proper cleanup when done with the mutex
 */
bool	create_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf("Failed to init mutex\n");
		mutex = NULL;
		return (false);
	}
	return (true);
}
