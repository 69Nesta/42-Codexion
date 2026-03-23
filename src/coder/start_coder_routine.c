/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_coder_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:30 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 17:47:31 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "codexion.h"
#include "time.h"


/*
	register to queue to get dongles
	wait for dongle
	start compile
	start debugging
	start refactoring
*/

int	start_coder_routine(t_sim *sim, t_coder *coder)
{
	// printf("Start coder's routine: %d | at: %d\n", coder->id, get_timestamp());
	while (coder->compiles_done < sim->number_of_compiles_required && !sim->stop)
	{
		register_coder_to_queue(sim, coder);
		wait_for_dongles(sim, coder);
		start_compiling(sim, coder);
		start_debugging(sim, coder);
		start_refactoring(sim, coder);
	}
	return (1);
}
