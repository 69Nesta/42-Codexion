/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:19:23 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:29:48 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "logger.h"
#include "clock.h"

int	monitor_routine(t_sim *sim)
{
	int		index;
	t_time	current_time;
	t_bool	all_coders_done;

	while (!sim->stop)
	{
		current_time = get_timestamp();
		index = 0;
		all_coders_done = TRUE;
		while (index < sim->number_of_coders)
		{
			if (!coder_has_finish_compiles(sim, &sim->coders[index]))
				all_coders_done = FALSE;
			if (coder_has_burnout(sim, &sim->coders[index], current_time))
			{
				pthread_mutex_lock(&sim->m_state);
				sim->state = SIM_FAIL;
				sim->stop = TRUE;
				log_action(sim, index, BURNOUT_ACTION);
				pthread_cond_broadcast(&sim->c_state);
				pthread_mutex_unlock(&sim->m_state);
				return (0);
			}
			index++;
		}
		if (all_coders_done)
		{
			pthread_mutex_lock(&sim->m_state);
			sim->stop = TRUE;
			pthread_cond_broadcast(&sim->c_state);
			pthread_mutex_unlock(&sim->m_state);
			return (1);
		}
	}
	return (1);
}
