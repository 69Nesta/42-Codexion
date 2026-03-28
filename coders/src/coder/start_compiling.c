/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_compiling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:31 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:21:35 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "logger.h"

int	start_compiling(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, COMPILE_ACTION);
	usleep(sim->time_to_compile * 1000);
	pthread_mutex_lock(&coder->mutex);
	coder->compiles_done++;
	coder->last_compile_time = get_timestamp();
	pthread_mutex_unlock(&coder->mutex);
	release_dongles(sim, coder);
	if (!is_running(sim))
		return (0);
	return (1);
}
