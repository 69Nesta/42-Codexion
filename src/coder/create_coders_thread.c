#include "codexion.h"
#include "coder.h"

#include <stdio.h>

int	create_coders_thread(t_sim *sim)
{
	int	index;

	index = 0;
	while (index < sim->number_of_coders)
	{
		if (pthread_create(&(sim->coders[index].thread), NULL, &coder_core,
				&(sim->coders[index])))
			break;
		index++;
	}
	if (index != sim->number_of_coders)
	{
		set_sim_state(sim, SIM_FAIL);
		while (index >= 0)
		{
			printf("Joining thread %d\n", index);
			pthread_join(sim->coders[index].thread, NULL);
			index--;
		}
		return (0);
	}
	return (1);
}
