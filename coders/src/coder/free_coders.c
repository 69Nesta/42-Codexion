/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:25 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 17:03:45 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"
#include "coder.h"

int	free_coders(t_sim *sim)
{
	int	index;

	if (!sim->coders)
		return (0);
	index = 0;
	while (index < sim->number_of_coders)
		pthread_mutex_destroy(&sim->coders[index++].mutex);
	free(sim->coders);
	sim->coders = NULL;
	return (0);
}
