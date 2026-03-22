#include "codexion.h"
#include <stdio.h>
#include "time.h"

int	release_dongles(t_sim *sim, t_coder *coder)
{
	if (!coder->left_dongle || !coder->right_dongle)
		return (0);
	// printf("Coder %d is releasing dongles | at: %ld\n", coder->id, get_timestamp());
	release_dongle(coder->left_dongle);
	coder->left_dongle = NULL;
	release_dongle(coder->right_dongle);
	coder->right_dongle = NULL;

	pthread_mutex_lock(&sim->m_queue);
	sim->dongles_availables += 2;
	pthread_cond_broadcast(&sim->c_dongles_availables);
	pthread_mutex_unlock(&sim->m_queue);
	return (1);
}
