/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_can_be_used.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:41 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 11:17:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"


int	dongle_can_be_used(t_sim *sim, t_dongle *dongle)
{
	(void)sim;

	return (
		!dongle->taken &&
		(
			// dongle->last_use_time + sim->dongle_cooldown <= get_timestamp() ||
			dongle->last_use_time <= get_timestamp() ||
			dongle->last_use_time == -1
		)
	);
}
