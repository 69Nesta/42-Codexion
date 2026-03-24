/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_has_burnout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:30:22 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 13:56:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "clock.h"


int coder_has_burnout(t_sim *sim, t_coder *coder, long current_time)
{
	return (time_left_to_burnout(sim, coder, current_time) <= 0);
}
