/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coders_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:23 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 11:18:18 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"

int	free_coders_queue(t_sim *sim)
{
	if (sim->queue)
		free(sim->queue);
	sim->queue = NULL;
	return (0);
}
