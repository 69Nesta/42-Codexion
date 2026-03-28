/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_left_to_burnout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:46:39 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 15:21:59 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_time	time_left_to_burnout(t_sim *sim, t_coder *coder, t_time current_time)
{
	t_time	time_since_last_compile;

	pthread_mutex_lock(&coder->mutex);
	time_since_last_compile = current_time - coder->last_compile_time;
	pthread_mutex_unlock(&coder->mutex);
	return (sim->time_to_burnout - time_since_last_compile);
}
