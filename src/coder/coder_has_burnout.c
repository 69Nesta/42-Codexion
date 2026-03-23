/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_has_burnout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:30:22 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 18:49:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "time.h"


int coder_has_burnout(t_sim *sim, t_coder *coder, long current_time)
{
	return (coder->last_compile_time + sim->time_to_burnout < current_time);
}
