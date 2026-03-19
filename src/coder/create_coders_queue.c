#include <stdlib.h>
#include "codexion.h"

int	create_coders_queue(t_sim *sim)
{
	int			index;

	sim->queue = malloc(sizeof(t_coder *) * sim->number_of_coders);
	if (!sim->queue)
		return (0);

	index = 0;
	while (index < sim->number_of_coders)
	{
		sim->queue[index] = NULL;

		index++;
	}

	return (1);
}