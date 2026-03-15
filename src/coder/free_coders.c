#include <stdlib.h>

#include "codexion.h"
#include "coder.h"

int	free_coders(t_codexion *codexion)
{
	if (!codexion->coders)
		return (1);

	free(codexion->coders);
	codexion->coders = NULL;

	return (0);
}