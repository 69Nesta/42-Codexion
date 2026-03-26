/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:44 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:09:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"

int	free_dongles(t_sim *sim)
{
	int	index;

	if (!sim->dongles)
		return (0);
	index = 0;
	while (index < sim->number_of_coders)
	{
		pthread_mutex_destroy(&sim->dongles[index].mutex);
		index++;
	}
	free(sim->dongles);
	sim->dongles = NULL;
	return (0);
}
