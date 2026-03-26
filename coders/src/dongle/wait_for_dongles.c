/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_dongles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:57 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 14:24:27 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	wait_for_dongles(t_sim *sim, t_coder *coder)
{
	pthread_mutex_lock(&sim->m_queue);
	while ((sim->dongles_availables < 2 || sim->queue[0] != coder)
		&& !sim->stop)
		pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);
	if (sim->stop)
	{
		pthread_mutex_unlock(&sim->m_queue);
		return (0);
	}
	sim->dongles_availables -= 2;
	remove_coder_from_queue(sim, coder);
	if (sim->dongles_availables > 0)
		pthread_cond_broadcast(&sim->c_dongles_availables);
	pthread_mutex_unlock(&sim->m_queue);
	if (take_dongles(sim, coder) < 2 || sim->stop)
		return (0);
	return (wait_dongles_cooldown(sim, coder));
}
