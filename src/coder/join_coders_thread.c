#include "codexion.h"


int	join_coders_thread(t_sim *sim)
{
	int	index;

	index = 0;
	while (index < sim->number_of_coders)
	{
		pthread_join(sim->coders[index].thread, NULL);
		index++;
	}

	return (1);
}
