/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:34 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 14:06:56 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include "coder.h"
# include "codexion.h"

int		error(char *str);
int		log_action(t_sim *sim, int coder_id, t_action action);

#endif