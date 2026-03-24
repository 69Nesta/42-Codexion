/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_dongles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:57 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 11:20:28 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "codexion.h"
#include "logger.h"

#include <stdio.h>
#include "clock.h"
#include <sys/time.h>
#include <time.h>


int wait_for_dongles(t_sim *sim, t_coder *coder)
{
	int index;
	int taken;
	// struct timespec ts;
	
	// clock_gettime(0, &ts);
	// ts.tv_nsec += 20;

	pthread_mutex_lock(&sim->m_queue);
	while ((sim->dongles_availables < 2 || sim->queue[0] != coder) && !sim->stop)
		pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);
		// pthread_cond_timedwait(&sim->c_dongles_availables, &sim->m_queue, &ts);

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

	index = 0;
	taken = 0;
	while (index < sim->number_of_coders && taken < 2 && !sim->stop)
	{
		pthread_mutex_lock(&sim->dongles[index].mutex);
		if (dongle_can_be_used(sim, &sim->dongles[index]))
		{
			sim->dongles[index].taken = TRUE;
			if (taken == 0)
				coder->left_dongle = &sim->dongles[index];
			else
				coder->right_dongle = &sim->dongles[index];
			taken++;
		}
		pthread_mutex_unlock(&sim->dongles[index].mutex);
		index++;
	}
	if (taken < 2)
	{
		error("Failed to take dongles\n");
		return (0);
	}

	return (wait_dongles_cooldown(sim, coder));
}
