/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:21:34 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 18:54:31 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	take_dongles(t_sim *sim, t_coder *coder)
{
	int	index;
	int	taken;

	index = 0;
	taken = 0;
	while (index < sim->number_of_coders && taken < 2 && is_running(sim))
	{
		pthread_mutex_lock(&sim->dongles[index].mutex);
		if (dongle_can_be_used(&sim->dongles[index]))
		{
			sim->dongles[index].taken = TRUE;
			if (taken == 0)
				coder->left_dongle = &sim->dongles[index];
			else
				coder->right_dongle = &sim->dongles[index];
			taken++;
		}
		pthread_mutex_unlock(&sim->dongles[index].mutex);
		index++;
	}
	return (taken);
}
