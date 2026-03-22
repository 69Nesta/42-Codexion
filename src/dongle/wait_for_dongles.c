#include <unistd.h>
#include "codexion.h"
#include "logger.h"
#include "time.h"
#include <stdio.h>


int	wait_for_dongles(t_sim *sim, t_coder *coder)
{
	int	index;
	int	taken;

	index = 0;
	taken = 0;
	pthread_mutex_lock(&sim->m_queue);
	while ((sim->dongles_availables < 2 || sim->queue[0] != coder) && !sim->stop)
		pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);
	if (sim->stop)
	{
		pthread_mutex_unlock(&sim->m_queue);
		return (0);
	}
	sim->dongles_availables -= 2;
	remove_coder_from_queue(sim, coder);
	pthread_mutex_unlock(&sim->m_queue);

	if (!(coder->compiles_done == 0 && coder->id % 2))
		usleep(sim->dongle_cooldown * 1000);
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
			log_action(sim, coder->id, TAKE_DONGLE_ACTION);
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
	// if (coder->left_dongle || coder->right_dongle)
	// 	log_action(sim, coder->id, TAKE_DONGLE_ACTION);
	return (1);
}
