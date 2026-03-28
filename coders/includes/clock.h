/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:20 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/28 16:32:21 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCK_H
# define CLOCK_H

# define _DEFAULT_SOURCE
# define _XOPEN_SOURCE 500
# define WAIT_CHECK 100
# include <unistd.h>

typedef long long	t_time;

void	start_timestamp(void);
t_time	get_timestamp(void);
t_time	get_time_us(void);

#endif