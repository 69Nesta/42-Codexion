/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_has_finish_compiles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:09:47 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 17:24:10 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	coder_has_finish_compiles(t_sim *sim, t_coder *coder)
{
	int	compiles_done;

	pthread_mutex_lock(&coder->mutex);
	compiles_done = coder->compiles_done;
	pthread_mutex_unlock(&coder->mutex);
	return (compiles_done >= sim->number_of_compiles_required);
}
