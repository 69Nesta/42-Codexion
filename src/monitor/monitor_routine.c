/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:19:23 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 18:59:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "logger.h"
#include "time.h"


int	monitor_routine(t_sim *sim)
{
	int		index;
	long	current_time;

	while (!sim->stop)
	{
		current_time = get_timestamp();
		index = 0;
		while (index < sim->number_of_coders)
		{
			if (coder_has_burnout(sim, &sim->coders[index], current_time))
			{
				log_action(sim, index, BURNOUT_ACTION);
				pthread_mutex_lock(&sim->m_state);
				sim->state = SIM_FAIL;
				sim->stop = TRUE;
				pthread_cond_broadcast(&sim->c_state);
				pthread_mutex_unlock(&sim->m_state);
				return (0);
			}
			index++;
		}
	}

	return (1);	
}
