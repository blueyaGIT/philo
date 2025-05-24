/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:59:05 by dalbano           #+#    #+#             */
/*   Updated: 2025/05/24 14:01:09 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
