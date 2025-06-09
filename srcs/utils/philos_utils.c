/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:01:12 by dalbano           #+#    #+#             */
/*   Updated: 2025/06/09 14:14:27 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_philo **philos, t_table *table)
{
	int	i;

	if (table->data->num_philo == 1)
	{
		philos[0]->r_fork_mutex = NULL;
		return ;
	}
	i = 1;
	while (i < table->data->num_philo)
	{
		philos[i - 1]->r_fork_mutex = &philos[i]->l_fork_mutex;
		i++;
	}
	philos[i - 1]->r_fork_mutex = &philos[0]->l_fork_mutex;
}

static t_philo	*birth_philo(int id, t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (error_msg(PHILO_MALLOC), NULL);
	memset(philo, 0, sizeof(t_philo));
	if (!create_mutex(&philo->philo_mutex))
		return (NULL);
	if (!create_mutex(&philo->philo_full_mutex))
		return (NULL);
	if (!create_mutex(&philo->last_meal_time_mutex))
		return (NULL);
	if (!create_mutex(&philo->l_fork_mutex))
		return (NULL);
	philo->id = id;
	philo->table = table;
	philo->philo_thread_created = true;
	return (philo);
}

t_philo	**philos_init(t_table *table)
{
	t_philo	**phils;
	t_philo *philo;
    int		i;

    phils = malloc(sizeof(t_philo *) * table->data->num_philo);
    if (!phils)
        return (error_msg(PHILO_MALLOC), NULL);
	table->philos = phils;
	i = -1;
    while (++i < table->data->num_philo)
    {
        philo = birth_philo(i + 1, table);
        if (!philo)
        {
            kill_all_mutex(table, i);
			free_phils(phils, i);
			return (NULL);
        }
        phils[i] = philo;
    }
	init_forks(phils, table);
    return (phils);
}
