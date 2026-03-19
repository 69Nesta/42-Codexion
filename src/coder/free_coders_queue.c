#include <stdlib.h>
#include "codexion.h"


int	free_coders_queue(t_sim *sim)
{
	pthread_mutex_lock(&sim->m_queue);
	if (sim->queue)
		free(sim->queue);
	sim->queue = NULL;
	pthread_mutex_unlock(&sim->m_queue);

	return (0);
}
