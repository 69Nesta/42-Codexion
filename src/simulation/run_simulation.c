/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:05 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:12:52 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "codexion.h"
#include "clock.h"

int	run_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->m_state);
	sim->state = SIM_RUNNING;
	start_timestamp();
	pthread_cond_broadcast(&sim->c_state);
	pthread_mutex_unlock(&sim->m_state);
	return (1);
}
