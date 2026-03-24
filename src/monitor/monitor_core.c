/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:12:59 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 18:59:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


void	*monitor_core(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	pthread_mutex_lock(&sim->m_state);
	while (sim->state == SIM_WAITING)
		pthread_cond_wait(&sim->c_state, &sim->m_state);
	pthread_mutex_unlock(&sim->m_state);
	if (sim->state == SIM_FAIL)
		return (NULL);
	
	monitor_routine(sim);
	
	return (NULL);
}
