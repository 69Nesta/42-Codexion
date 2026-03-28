/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_dongles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:50 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:19:14 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	release_dongles(t_sim *sim, t_coder *coder)
{
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
