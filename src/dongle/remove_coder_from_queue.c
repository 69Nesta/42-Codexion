/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_coder_from_queue.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:53 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 16:18:09 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>


int remove_coder_from_queue(t_sim *sim, t_coder *coder)
{
    int index;
    int found;

    index = 0;
    found = 0;

	while (index < sim->number_of_coders)
	{
		if (sim->queue[index] == coder)
			found = 1;
		if (found && index + 1 < sim->number_of_coders)
			sim->queue[index] = sim->queue[index + 1];
		index++;
	}
	if (found)
		sim->queue[index - 1] = NULL;

    return (found);
}
