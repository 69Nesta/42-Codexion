#include "codexion.h"
#include <stdio.h>


int	remove_coder_from_queue(t_sim *sim, t_coder *coder)
{
	int	index;

	index = 1;
	if (sim->queue[0] == coder)
	{
		sim->queue[0] = NULL;
		while (index < sim->number_of_coders && sim->queue[index] != NULL)
		{
			sim->queue[index - 1] = sim->queue[index];
			sim->queue[index] = NULL;
			index++;
		}
	}
	pthread_cond_broadcast(&sim->c_dongles_availables);
	return (1);
}
