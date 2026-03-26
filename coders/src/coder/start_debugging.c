/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_debugging.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:34 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 11:16:33 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "codexion.h"
#include "logger.h"

int	start_debugging(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, DEBUG_ACTION);
	usleep(sim->time_to_debug * 1000);
	if (sim->stop)
		return (0);
	return (1);
}
