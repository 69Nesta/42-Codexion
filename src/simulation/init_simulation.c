#include "codexion.h"


int	init_simulation(t_sim *sim)
{
	sim->stop = 0;
	sim->state = SIM_WAITING;
	sim->coders = NULL;
	sim->dongles = NULL;
	sim->queue = NULL;

	if (pthread_mutex_init(&sim->m_queue, NULL))
		return (0);
	if (pthread_mutex_init(&sim->m_log, NULL))
		return (cleanup_simulation(sim, 1));
	if (pthread_mutex_init(&sim->m_state, NULL))
		return (cleanup_simulation(sim, 2));

	if (pthread_cond_init(&sim->c_state, NULL))
		return (cleanup_simulation(sim, 3));

	if (!create_dongles(sim))
		return (cleanup_simulation(sim, 4));
	if (!create_coders_queue(sim))
		return (cleanup_simulation(sim, 5));
	if (!create_coders(sim))
		return (cleanup_simulation(sim, 6));
	if (!create_coders_thread(sim))
		return (cleanup_simulation(sim, 7));
	return (1);
}
