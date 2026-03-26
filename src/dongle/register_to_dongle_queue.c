/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_to_dongle_queue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:46 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:08:13 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"

int	register_coder_to_queue(t_sim *sim, t_coder *coder)
{
	pthread_mutex_lock(&sim->m_queue);
	if (sim->scheduler == FIFO)
		insert_into_queue_fifo(sim, coder);
	else if (sim->scheduler == EDF)
		insert_into_queue_edf(sim, coder, get_timestamp());
	pthread_mutex_unlock(&sim->m_queue);
	return (1);
}
