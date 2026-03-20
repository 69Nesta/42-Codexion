#include <stdio.h>

#include "codexion.h"
#include "time.h"


/*
	register to queue to get dongles
	wait for dongle
	start compile
	start debugging
	start refactoring
*/

int	start_coder_routine(t_sim *sim, t_coder *coder)
{
	printf("Start coder's routine: %d | at: %d\n", coder->id, get_timestamp());
	while (coder->compiles_done < sim->number_of_compiles_required && !sim->stop)
	{

	}
	return (1);
}
