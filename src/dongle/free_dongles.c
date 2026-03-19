#include <stdlib.h>
#include "codexion.h"
#include "dongle.h"


int	free_dongles(t_sim *sim)
{
	int	index;

	if (!sim->dongles)
		return (0);

	index = 0;
	while (index < sim->number_of_coders)
	{
		pthread_mutex_destroy(&sim->dongles[index].mutex);
		index++;
	}
	free(sim->dongles);
	sim->dongles = NULL;

	return (0);
}
