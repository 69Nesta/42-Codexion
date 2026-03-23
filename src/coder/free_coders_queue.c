#include <stdlib.h>
#include "codexion.h"


int	free_coders_queue(t_sim *sim)
{
	if (sim->queue)
		free(sim->queue);
	sim->queue = NULL;

	return (0);
}
