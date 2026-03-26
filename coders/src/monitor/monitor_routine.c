/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:19:23 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 16:29:24 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"
#include <stdio.h>

int	monitor_routine(t_sim *sim)
{
	t_bool	all_coders_done;

	while (!sim->stop)
	{
		if (!check_coders(sim, get_timestamp(), &all_coders_done))
			return (0);
		if (all_coders_done)
		{
			pthread_mutex_lock(&sim->m_state);
			pthread_mutex_lock(&sim->m_queue);
			sim->stop = TRUE;
			pthread_cond_broadcast(&sim->c_state);
			pthread_cond_broadcast(&sim->c_dongles_availables);
			pthread_mutex_unlock(&sim->m_queue);
			pthread_mutex_unlock(&sim->m_state);
			return (1);
		}
	}
	return (1);
}
