#include "codexion.h"
#include "time.h"

int	wait_for_dongles(t_sim *sim, t_coder *coder)
{
	int	index;
	int	taken;

	pthread_mutex_lock(&sim->m_dongles_availables);
	while (sim->dongles_availables < 2)
		pthread_cond_wait(&sim->c_dongles_availables, &sim->m_dongles_availables);
	sim->dongles_availables -= 2;
	pthread_mutex_unlock(&sim->m_dongles_availables);

	// finds dongles not takens
	index = 0;
	taken = 0;
	while (index < sim->number_of_coders && taken < 2)
	{
		pthread_mutex_lock(&sim->dongles[index].mutex);
		if (dongle_can_be_used(sim, &sim->dongles[index]));
		{
			sim->dongles[index].taken = TRUE;
			sim->dongles[index].last_use_time = get_timestamp();
		}
		pthread_mutex_unlock(&sim->dongles[index].mutex);
		index++;
	}
}
