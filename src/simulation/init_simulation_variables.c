/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation_variables.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:44:31 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 10:44:50 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	init_simulation_variables(t_sim *sim)
{
	sim->stop = 0;
	sim->state = SIM_WAITING;
	sim->coders = NULL;
	sim->dongles = NULL;
	sim->queue = NULL;
	sim->dongles_availables = sim->number_of_coders;

	return (1);
}
