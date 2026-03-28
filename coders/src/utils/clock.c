/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:17 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 16:27:24 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <sys/time.h>

static struct timeval	*get_start_time(void)
{
	static struct timeval	start_time;

	return (&start_time);
}

void	start_timestamp(void)
{
	gettimeofday(get_start_time(), NULL);
}

t_time	get_timestamp(void)
{
	struct timeval	current_time;
	struct timeval	*start_time;

	start_time = get_start_time();
	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec - start_time->tv_sec) * 1000)
		+ ((current_time.tv_usec - start_time->tv_usec) / 1000));
}

t_time	get_time_us(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000000L + ts.tv_nsec / 1000);
}
