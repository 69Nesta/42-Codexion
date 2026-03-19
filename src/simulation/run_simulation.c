#include <stdio.h>
#include "codexion.h"
#include "time.h"

int run_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->m_state);

	printf("Broadcasting\n");
	sim->state = SIM_RUNNING;
	start_timestamp();
	pthread_cond_broadcast(&sim->c_state);

	pthread_mutex_unlock(&sim->m_state);

	return (1);
}
