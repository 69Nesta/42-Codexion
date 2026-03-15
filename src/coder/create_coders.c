#include <stdlib.h>

#include "codexion.h"
#include "coder.h"

int	create_coders(t_codexion *codexion)
{
	int	index;

	codexion->coders = malloc(sizeof(t_coder) * codexion->number_of_coders);
	if (!codexion->coders)
		return (1);

	index = 0;
	while (index < codexion->number_of_coders)
	{
		codexion->coders[index].id = index;
		codexion->coders[index].state = IDLE;
		codexion->coders[index].compiles_done = 0;
		codexion->coders[index].last_compile_time = -1;

		index++;
	}
	return (0);
}
