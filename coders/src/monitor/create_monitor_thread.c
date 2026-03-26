/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor_thread.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:09:16 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:24:59 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_monitor_thread(t_sim *sim)
{
	return (!pthread_create(&sim->monitor_thread, NULL, monitor_core, sim));
}
