/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sim_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:07 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:13:51 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	set_sim_state(t_sim *sim, t_sim_state state)
{
	pthread_mutex_lock(&sim->m_state);
	sim->state = state;
	pthread_cond_broadcast(&sim->c_state);
	pthread_mutex_unlock(&sim->m_state);
	return (1);
}
