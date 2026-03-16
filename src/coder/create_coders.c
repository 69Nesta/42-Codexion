#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "codexion.h"
#include "coder.h"
#include "logger.h"


/*
steps for corders:
- finds 2 dongles (locks them)
- compiles (sleeps for time_to_compile)
- increments compile count
- releases dongles (unlocks them)
- debugs (sleeps for time_to_debug)
- refactors (sleeps for time_to_refactor)
*/

void *coder_logic(void *v_coder)
{
	t_coder		*coder = (t_coder *)v_coder;
	// t_codexion	*codexion = coder->codexion;
	
	// printf("From thead coder: %d\n", coder->id);

	log_action(coder->id, TAKE_DONGLE_ACTION);
	log_action(coder->id, TAKE_DONGLE_ACTION);
	log_action(coder->id, COMPILE_ACTION);

	usleep(100000);

	log_action(coder->id, REFACTOR_ACTION);

	// while (coder->compiles_done < )

	return (0);
}


int	create_coders(t_codexion *codexion)
{
	int			index;

	codexion->coders = malloc(sizeof(t_coder) * codexion->number_of_coders);
	if (!codexion->coders)
		return (1);

	index = 0;
	while (index < codexion->number_of_coders)
	{
		codexion->coders[index].id = index;
		codexion->coders[index].state = IDLE;
		codexion->coders[index].compiles_done = 0;
		codexion->coders[index].last_compile_time = -1;
		codexion->coders[index].right_dongle = -1;
		codexion->coders[index].left_dongle = -1;
		codexion->coders[index].codexion = codexion;

		index++;
	}
	return (0);
}

int create_threads(t_codexion *codexion)
{
	int			index;

	index = 0;
	while (index < codexion->number_of_coders)
	{
		pthread_create(
			&(codexion->coders[index].thread),
			NULL,
			&coder_logic,
			&(codexion->coders[index])
		);
		index++;
	}

	return (0);
}
