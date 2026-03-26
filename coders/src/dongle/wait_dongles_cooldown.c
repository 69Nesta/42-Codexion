/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_dongles_cooldown.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:55 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 19:00:25 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "codexion.h"
#include "logger.h"
#include "clock.h"

int	wait_dongles_cooldown(t_sim *sim, t_coder *coder)
{
	t_time	left_remaining;
	t_time	right_remaining;

	left_remaining = 0;
	if (coder->left_dongle->last_use_time != -1)
		left_remaining = sim->dongle_cooldown - (
				get_timestamp() - coder->left_dongle->last_use_time);
	right_remaining = 0;
	if (coder->right_dongle->last_use_time != -1)
		right_remaining = sim->dongle_cooldown - (
				get_timestamp() - coder->right_dongle->last_use_time);
	if (left_remaining > 0 || right_remaining > 0)
		usleep((left_remaining * (left_remaining > right_remaining)
				+ right_remaining * (right_remaining >= left_remaining))
			* 1000);
	if (!is_running(sim))
	{
		return (0);
	}
	log_action(sim, coder->id, TAKE_DONGLE_ACTION);
	log_action(sim, coder->id, TAKE_DONGLE_ACTION);
	return (1);
}
