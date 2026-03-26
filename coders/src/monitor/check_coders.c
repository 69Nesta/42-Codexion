/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:27:14 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 18:56:42 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "logger.h"

int	check_coders(t_sim *sim, t_time current_time, t_bool *all_coders_done)
{
	int		index;

	index = 0;
	*all_coders_done = TRUE;
	while (index < sim->number_of_coders)
	{
		if (!coder_has_finish_compiles(sim, &sim->coders[index]))
			*all_coders_done = FALSE;
		if (coder_has_burnout(sim, &sim->coders[index], current_time))
		{
			pthread_mutex_lock(&sim->m_state);
			sim->state = SIM_FAIL;
			sim->stop = TRUE;
			pthread_cond_broadcast(&sim->c_state);
			pthread_mutex_unlock(&sim->m_state);
			pthread_mutex_lock(&sim->m_queue);
			pthread_cond_broadcast(&sim->c_dongles_availables);
			pthread_mutex_unlock(&sim->m_queue);
			log_action(sim, index, BURNOUT_ACTION);
			return (0);
		}
		index++;
	}
	return (1);
}
