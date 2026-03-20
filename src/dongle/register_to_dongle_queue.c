#include "codexion.h"

int	register_coder_to_queue(t_sim *sim, t_coder *coder)
{
	int	index;

	index = 0;
	pthread_mutex_lock(&sim->m_queue);

	while (sim->queue[index] != NULL && index < sim->number_of_coders)
		index++;

	sim->queue[index] = coder;
	pthread_mutex_unlock(&sim->m_queue);
	return (1);
}
