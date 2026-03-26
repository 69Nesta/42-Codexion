/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:20 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 13:20:39 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCK_H
# define CLOCK_H

typedef long long	t_time;

void	start_timestamp(void);
t_time	get_timestamp(void);

#endif