#include <unistd.h>
#include "codexion.h"
#include "logger.h"

int	start_refactoring(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, REFACTOR_ACTION);
	usleep(sim->time_to_refactor * 1000);

	return (1);
}
