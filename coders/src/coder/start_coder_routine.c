/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_coder_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:30 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 19:00:38 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "codexion.h"
#include "clock.h"

int	start_coder_routine(t_sim *sim, t_coder *coder)
{
	while (coder->compiles_done < sim->number_of_compiles_required
		&& is_running(sim))
	{
		register_coder_to_queue(sim, coder);
		if (!wait_for_dongles(sim, coder))
			return (0);
		if (!start_compiling(sim, coder))
			return (0);
		if (coder_has_finish_compiles(sim, coder))
			return (1);
		if (!start_debugging(sim, coder))
			return (0);
		start_refactoring(sim, coder);
	}
	return (1);
}
