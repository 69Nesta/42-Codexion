/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_dongle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:48 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 11:17:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"


int	release_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->taken = FALSE;
	dongle->last_use_time = get_timestamp();
	pthread_mutex_unlock(&dongle->mutex);
	return (1);
}
