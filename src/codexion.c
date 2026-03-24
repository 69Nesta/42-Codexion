/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:24 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 14:26:38 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "codexion.h"
#include "args.h"
#include "clock.h"
#include "logger.h"


int main(int argc, char **argv)
{
	t_sim	sim;

	sim.stop = 0;
	if (ft_check_args(&sim, argc, argv))
		return (1);

	// printf("Number of coders: %d\n", sim.number_of_coders);
	// printf("Time to burnout: %d\n", sim.time_to_burnout);
	// printf("Time to compile: %d\n", sim.time_to_compile);
	// printf("Time to debug: %d\n", sim.time_to_debug);
	// printf("Time to refactor: %d\n", sim.time_to_refactor);
	// printf("Number of compiles required: %d\n", sim.number_of_compiles_required);
	// printf("Dongle cooldown: %d\n", sim.dongle_cooldown);
	// printf("Scheduler algorithm: %d\n\n-----------\n\n", sim.scheduler);

	if (!init_simulation(&sim))
		return (error("Something append during initalization !\n"));

	run_simulation(&sim);

	join_monitor_thread(&sim);
	join_coders_thread(&sim);

	cleanup_simulation(&sim, 0);
	return (0);
}
