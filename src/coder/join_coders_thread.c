/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_coders_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:28 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 11:18:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codexion.h"

int	join_coders_thread(t_sim *sim)
{
	int	index;

	index = 0;
	while (index < sim->number_of_coders)
	{
		pthread_join(sim->coders[index].thread, NULL);
		index++;
	}
	return (1);
}
