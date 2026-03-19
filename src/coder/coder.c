#include "codexion.h"

/*
steps for corders:
- finds 2 dongles (locks them)
- compiles (sleeps for time_to_compile)
- increments compile count
- releases dongles (unlocks them)
- debugs (sleeps for time_to_debug)
- refactors (sleeps for time_to_refactor)
*/


void coder_routine(void *v_coder)
{
	t_coder		*coder = (t_coder *)v_coder;
	t_sim		*sim = coder->sim;

	while (1)
	{
		
	}

	if (coder->id % 2 == 0)
		usleep(1500);

	return (0);
}

int create_threads(t_sim *sim)
{
	int			index;

	index = 0;
	while (index < sim->number_of_coders)
	{
		pthread_create(
			&(sim->coders[index].thread),
			NULL,
			&coder_routine,
			&(sim->coders[index])
		);
		index++;
	}

	return (0);
}

