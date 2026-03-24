/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_into_queue_fifo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:36:18 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 16:19:41 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	insert_into_queue_fifo(t_sim *sim, t_coder *coder)
{
	int		index;
	
	index = 0;
	while (sim->queue[index] != NULL && index < sim->number_of_coders)
		index++;
	sim->queue[index] = coder;

	return (1);
}
