/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:34:05 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 18:38:57 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_running(t_sim *sim)
{
	pthread_mutex_lock(&sim->m_state);
	if (sim->stop)
	{
		pthread_mutex_unlock(&sim->m_state);
		return (0);
	}
	pthread_mutex_unlock(&sim->m_state);
	return (1);
}
