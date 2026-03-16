#include <stdio.h>
#include <pthread.h>

#include "codexion.h"
#include "args.h"
#include "time.h"
#include "utils.h"
#include "coder.h"


int main(int argc, char **argv)
{
	t_codexion	codexion;

	start_timestamp();
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

	/*
	Initialize coders and dongles here
	*/

	log_action(0, TAKE_DONGLE_ACTION);

	return (0);
}
