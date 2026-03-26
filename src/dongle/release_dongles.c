/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_dongles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:50 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 11:17:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>
#include "clock.h"

int	release_dongles(t_sim *sim, t_coder *coder)
{
	// if (!coder->left_dongle || !coder->right_dongle)
	// 	return (0);
	// printf("\e[0;35mCoder %d is releasing dongles | at: %ld | dongle1: %d | dongle2: %d\n\e[0m", coder->id, get_timestamp(), coder->left_dongle->id, coder->right_dongle->id);
	if (coder->left_dongle)
		release_dongle(coder->left_dongle);
	coder->left_dongle = NULL;

	if (coder->right_dongle)
		release_dongle(coder->right_dongle);
	coder->right_dongle = NULL;

	pthread_mutex_lock(&sim->m_queue);
	sim->dongles_availables += 2;
	pthread_cond_broadcast(&sim->c_dongles_availables);
	pthread_mutex_unlock(&sim->m_queue);
	return (1);
}
