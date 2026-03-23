/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:03 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 18:12:37 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"


int	init_simulation(t_sim *sim)
{
	sim->stop = 0;
	sim->state = SIM_WAITING;
	sim->coders = NULL;
	sim->dongles = NULL;
	sim->queue = NULL;
	sim->dongles_availables = sim->number_of_coders;
	if (pthread_mutex_init(&sim->m_queue, NULL))
		return (0);
	if (pthread_mutex_init(&sim->m_log, NULL))
		return (cleanup_simulation(sim, 1));
	if (pthread_mutex_init(&sim->m_state, NULL))
		return (cleanup_simulation(sim, 2));
	if (pthread_cond_init(&sim->c_state, NULL))
		return (cleanup_simulation(sim, 3));
	if (pthread_cond_init(&sim->c_dongles_availables, NULL))
		return (cleanup_simulation(sim, 4));
	if (!create_dongles(sim))
		return (cleanup_simulation(sim, 5));
	if (!create_coders_queue(sim))
		return (cleanup_simulation(sim, 6));
	if (!create_coders(sim))
		return (cleanup_simulation(sim, 7));
	if (!create_monitor_thread(sim))
		return (cleanup_simulation(sim, 8));
	if (!create_coders_thread(sim))
		return (cleanup_simulation(sim, 9));
	return (1);
}
