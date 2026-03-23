#include "codexion.h"
#include <stdio.h>
#include "time.h"

int	register_coder_to_queue(t_sim *sim, t_coder *coder)
{
	int	index;

	index = 0;
	pthread_mutex_lock(&sim->m_queue);

	while (sim->queue[index] != NULL && index < sim->number_of_coders)
		index++;

	// printf("\e[0;36mCoder %d is registering to queue pos %d | at: %ld\n\e[0m", coder->id, index, get_timestamp());

	sim->queue[index] = coder;
	pthread_mutex_unlock(&sim->m_queue);
	return (1);
}
