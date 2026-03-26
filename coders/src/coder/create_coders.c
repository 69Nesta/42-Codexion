/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:21 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 17:24:28 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"
#include "coder.h"

int	create_coders(t_sim *sim)
{
	int			index;

	sim->coders = malloc(sizeof(t_coder) * sim->number_of_coders);
	if (!sim->coders)
		return (0);
	index = 0;
	while (index < sim->number_of_coders)
	{
		sim->coders[index].id = index;
		sim->coders[index].state = IDLE;
		sim->coders[index].compiles_done = 0;
		sim->coders[index].last_compile_time = 0;
		sim->coders[index].right_dongle = NULL;
		sim->coders[index].left_dongle = NULL;
		sim->coders[index].sim = sim;
		if (pthread_mutex_init(&sim->coders[index].mutex, NULL) != 0)
			break ;
		index++;
	}
	while (index < sim->number_of_coders && index >= 0)
		pthread_mutex_destroy(&sim->coders[index--].mutex);
	if (index < sim->number_of_coders)
		free(sim->coders);
	return (index == sim->number_of_coders);
}
