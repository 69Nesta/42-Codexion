/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_monitor_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:13:19 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 18:16:58 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	join_monitor_thread(t_sim *sim)
{
	if (pthread_join(sim->monitor_thread, NULL) != 0)
		return (1);
	return (0);
}
