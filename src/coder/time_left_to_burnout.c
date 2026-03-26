/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_left_to_burnout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:46:39 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 13:12:42 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


long	time_left_to_burnout(t_sim *sim, t_coder *coder, long current_time)
{
	long time_since_last_compile = current_time - coder->last_compile_time;
	return (sim->time_to_burnout - time_since_last_compile);
}
