/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:23 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 14:05:24 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "codexion.h"
# define ARGS_REQUIRED	8

int	ft_fill_settings(t_sim *settings, int argc, char **argv);
int	ft_check_settings(t_sim *settings);
int ft_check_args(t_sim *settings, int argc, char **argv);

#endif