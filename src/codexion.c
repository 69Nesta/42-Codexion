#include <stdio.h>
#include <pthread.h>

#include "codexion.h"
#include "args.h"
#include "time.h"
#include "logger.h"


int	run_all_coders(t_codexion *codexion)
{
	int	index;

	index = 0;
	while (index < codexion->number_of_coders)
	{
		pthread_join(codexion->coders[index].thread, NULL);
		index++;
	}

	return (0);
}


int main(int argc, char **argv)
{
	t_codexion	codexion;

	if (ft_check_args(&codexion, argc, argv))
		return (1);

	printf("Number of coders: %d\n", codexion.number_of_coders);
	printf("Time to burnout: %d\n", codexion.time_to_burnout);
	printf("Time to compile: %d\n", codexion.time_to_compile);
	printf("Time to debug: %d\n", codexion.time_to_debug);
	printf("Time to refactor: %d\n", codexion.time_to_refactor);
	printf("Number of compiles required: %d\n", codexion.number_of_compiles_required);
	printf("Dongle cooldown: %d\n", codexion.dongle_cooldown);
	printf("Scheduler algorithm: %d\n\n-----------\n\n", codexion.scheduler);

	create_coders(&codexion);
	create_dongles(&codexion);


	start_timestamp();
	create_threads(&codexion);
	run_all_coders(&codexion);

	free_dongles(&codexion);
	free_coders(&codexion);

	return (0);
}
