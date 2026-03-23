/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:12 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 17:48:13 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "codexion.h"
#include "colors.h"
#include "coder.h"
#include "time.h"

int error(char *str)
{
	return (printf("%sERROR:%s %s", RED, CRESET, str));
}

int log_action(t_sim *sim, int coder_id, t_action action)
{
	const char *action_str[] = {
		[TAKE_DONGLE_ACTION] = "has taken a dongle",
		[COMPILE_ACTION] = "is compiling",
		[DEBUG_ACTION] = "is debugging",
		[REFACTOR_ACTION] = "is refactoring",
		[BURNOUT_ACTION] = "burned out"
	};

	pthread_mutex_lock(&sim->m_log);
	printf("%ld %d %s\n", get_timestamp(), coder_id, action_str[action]);
	pthread_mutex_unlock(&sim->m_log);

	return (1);
}
