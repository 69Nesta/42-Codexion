#include <stdlib.h>
#include "codexion.h"
#include "dongle.h"


int	create_dongles(t_sim *sim)
{
	int	index;

	sim->dongles = malloc(sizeof(t_dongle) * sim->number_of_coders);
	if (!sim->dongles)
		return (0);

	index = 0;
	while (index < sim->number_of_coders)
	{
		sim->dongles[index].id = index;
		sim->dongles[index].taken = FALSE;
		sim->dongles[index].last_use_time = -1;
		pthread_mutex_init(&sim->dongles[index].mutex, NULL);
		index++;
	}
	return (1);
}
