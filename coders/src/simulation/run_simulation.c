/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:05 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:19:38 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	run_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->m_state);
	sim->state = SIM_RUNNING;
	start_timestamp();
	pthread_cond_broadcast(&sim->c_state);
	pthread_mutex_unlock(&sim->m_state);
	return (1);
}
