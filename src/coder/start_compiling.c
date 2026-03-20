#include <unistd.h>
#include "codexion.h"
#include "logger.h"


int	start_compiling(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, COMPILE_ACTION);
	usleep(sim->time_to_compile * 1000);
	coder->compiles_done++;
	release_dongles(sim, coder);

	return (1);
}
