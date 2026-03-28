/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:28:12 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 16:40:00 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	wait(t_sim *sim, t_time usec)
{
	t_time	start;
	t_time	elapsed;

	start = get_time_us();
	while (1)
	{
		if (!is_running(sim))
			return (0);
		elapsed = get_time_us() - start;
		if (elapsed >= usec)
			return (1);
		if (usec - elapsed > WAIT_CHECK)
			usleep(WAIT_CHECK);
		else
			usleep(usec - elapsed);
	}
}
