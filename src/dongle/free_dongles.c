#include <stdlib.h>
#include "codexion.h"
#include "dongle.h"


int	free_dongles(t_codexion *codexion)
{
	int	index;

	if (!codexion->dongles)
		return (1);

	index = 0;
	while (index < codexion->number_of_coders)
	{
		pthread_mutex_destroy(&codexion->dongles[index].mutex);
		index++;
	}
	free(codexion->dongles);
	codexion->dongles = NULL;

	return (0);
}
