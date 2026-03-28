/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coders_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:19 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:18:08 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_coders_thread(t_sim *sim)
{
	int	index;

	index = 0;
	while (index < sim->number_of_coders)
	{
		if (pthread_create(&(sim->coders[index].thread), NULL, &coder_core,
				&(sim->coders[index])))
			break ;
		index++;
	}
	if (index != sim->number_of_coders)
	{
		set_sim_state(sim, SIM_FAIL);
		while (index > 0)
			pthread_join(sim->coders[--index].thread, NULL);
		return (0);
	}
	return (1);
}
