/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_into_queue_edf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:36:18 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:09:30 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"

int	insert_into_queue_edf(t_sim *sim, t_coder *coder, t_time time)
{
	int		index;
	t_time	coder_time;
	t_time	current_time;
	t_coder	*temp;

	index = 0;
	coder_time = time_left_to_burnout(sim, coder, time);
	while (index < sim->number_of_coders && sim->queue[index] != NULL)
	{
		current_time = time_left_to_burnout(sim, sim->queue[index], time);
		if (current_time > coder_time)
			break ;
		if (current_time == coder_time && sim->queue[index]->id > coder->id)
			break ;
		index++;
	}
	while (index < sim->number_of_coders && sim->queue[index] != NULL)
	{
		temp = sim->queue[index];
		sim->queue[index] = coder;
		coder = temp;
		index++;
	}
	sim->queue[index] = coder;
	return (1);
}
