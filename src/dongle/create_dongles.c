#include <stdlib.h>
#include "codexion.h"
#include "dongle.h"


int	create_dongles(t_codexion *codexion)
{
	int	index;

	codexion->dongles = malloc(sizeof(t_dongle) * codexion->number_of_coders);
	if (!codexion->dongles)
		return (1);

	index = 0;
	while (index < codexion->number_of_coders)
	{
		codexion->dongles[index].taken = FALSE;
		codexion->dongles[index].last_use_time = -1;
		pthread_mutex_init(&codexion->dongles[index].mutex, NULL);
		index++;
	}
	return (0);
}
