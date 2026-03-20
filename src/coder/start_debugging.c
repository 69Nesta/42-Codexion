#include <unistd.h>
#include "codexion.h"
#include "logger.h"

int	start_debugging(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, DEBUG_ACTION);
	usleep(sim->time_to_debug * 1000);

	return (1);
}
