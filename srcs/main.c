/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:52:14 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/09 14:14:29 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	**philos;
	t_table	table;
	t_data	data;

	philos = NULL;
	if (ac < 5 || ac > 6)
		return (error_msg(USAGE), EXIT_FAILURE);
	if (!handle_input(&data, av + 1) || !table_init(&table, &data))
		return (EXIT_FAILURE);
	philos = philos_init(&table);
	(void)philos;
	TEST("T1\n");
	return (0);
}
