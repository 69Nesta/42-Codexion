/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:00 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 14:40:42 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	cleanup_simulation(t_sim *sim, int index)
{
	if (index >= 9)
	{
		set_sim_state(sim, SIM_FAIL);
		join_monitor_thread(sim);
	}
	if (index >= 1 || index == 0)
		pthread_mutex_destroy(&sim->m_queue);
	if (index >= 2 || index == 0)
		pthread_mutex_destroy(&sim->m_log);
	if (index >= 3 || index == 0)
		pthread_mutex_destroy(&sim->m_state);
	if (index >= 4 || index == 0)
		pthread_cond_destroy(&sim->c_state);
	if (index >= 5 || index == 0)
		pthread_cond_destroy(&sim->c_dongles_availables);
	if (index >= 6 || index == 0)
		free_dongles(sim);
	if (index >= 7 || index == 0)
		free_coders_queue(sim);
	if (index >= 8 || index == 0)
		free_coders(sim);
	return (0);
}
