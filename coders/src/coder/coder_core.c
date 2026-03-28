/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:13 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:18:19 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_core(void *arg)
{
	t_coder	*coder;
	t_sim	*sim;

	coder = (t_coder *)arg;
	sim = coder->sim;
	pthread_mutex_lock(&sim->m_state);
	while (sim->state == SIM_WAITING)
		pthread_cond_wait(&sim->c_state, &sim->m_state);
	if (sim->state != SIM_RUNNING)
	{
		pthread_mutex_unlock(&sim->m_state);
		return (NULL);
	}
	pthread_mutex_unlock(&sim->m_state);
	if (coder->id % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&sim->m_log);
	pthread_mutex_unlock(&sim->m_log);
	start_coder_routine(sim, coder);
	return (NULL);
}
