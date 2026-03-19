#include <stdlib.h>

#include "codexion.h"
#include "coder.h"

int	free_coders(t_sim *sim)
{
	if (!sim->coders)
		return (0);
	
	free(sim->coders);

	sim->coders = NULL;
	return (0);
}
