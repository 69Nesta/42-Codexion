/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_can_be_used.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:41 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 12:11:40 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"

int	dongle_can_be_used(t_dongle *dongle)
{
	return (
		!dongle->taken
		&& (
			dongle->last_use_time <= get_timestamp()
			|| dongle->last_use_time == -1
		)
	);
}
