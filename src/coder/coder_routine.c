#include <unistd.h>
#include "codexion.h"
#include "logger.h"

void	*coder_routine(void* arg)
{
	t_coder	*coder	= (t_coder *)arg;
	t_sim	*sim	= coder->sim;

	pthread_mutex_lock(&sim->m_state);
	while (sim->state == SIM_WAITING)
		pthread_cond_wait(&sim->c_state, &sim->m_state);
	if (sim->state != SIM_RUNNING)
	{
		pthread_mutex_unlock(&sim->m_state);
		return (NULL);
	}
	pthread_mutex_unlock(&sim->m_state);

	if (coder->id % 2 == 0)
		usleep(1500);

	// coder_routine there
	log_action(sim, coder->id, TAKE_DONGLE_ACTION);

	return (NULL);
}
