/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:04:30 by dalbano           #+#    #+#             */
/*   Updated: 2025/05/24 14:06:58 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(t_error_type type)
{
	if (type == USAGE)
		printf("USAGE ERROR\n");
	return ;
}
