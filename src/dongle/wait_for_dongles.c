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
	while (sim->dongles_availables < 2 && !sim->stop && sim->queue[0] != coder)
		pthread_cond_wait(&sim->c_dongles_availables, &sim->m_queue);
	sim->dongles_availables -= 2;
	remove_coder_from_queue(sim, coder);
	pthread_mutex_unlock(&sim->m_queue);

	if (coder->compiles_done > 0)
		usleep(sim->dongle_cooldown * 1000); // wait dongles cooldown
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
	return (1);
}
