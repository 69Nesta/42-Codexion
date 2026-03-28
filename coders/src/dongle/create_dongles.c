/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dongles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:39 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:18:46 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_dongles(t_sim *sim)
{
	int	index;

	sim->dongles = malloc(sizeof(t_dongle) * sim->number_of_coders);
	if (!sim->dongles)
		return (0);
	index = 0;
	while (index < sim->number_of_coders)
	{
		sim->dongles[index].id = index;
		sim->dongles[index].taken = FALSE;
		sim->dongles[index].last_use_time = -1;
		if (pthread_mutex_init(&sim->dongles[index].mutex, NULL))
			break ;
		index++;
	}
	while (index != sim->number_of_coders && index > 0)
		pthread_mutex_destroy(&sim->dongles[--index].mutex);
	if (index <= 0)
	{
		free(sim->dongles);
		sim->dongles = NULL;
		return (0);
	}
	return (1);
}
