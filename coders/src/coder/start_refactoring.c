/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_refactoring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:36 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:21:58 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "logger.h"

int	start_refactoring(t_sim *sim, t_coder *coder)
{
	log_action(sim, coder->id, REFACTOR_ACTION);
	usleep(sim->time_to_refactor * 1000);
	return (1);
}
