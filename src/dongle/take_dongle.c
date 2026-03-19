#include <pthread.h>
#include "coder.h"
#include "dongle.h"

// int	dongles_availables(t_coder)


int	take_dongles(t_coder *coder, t_sim *sim)
{
	int i;
	int	i_dongle_1;
	int	i_dongle_2;

	i = 0;
	while(sim->dongles && i < sim->number_of_coders)
	{
		if (sim->dongles[i].mutex)
		// sim->dongles[i]
	}
}
