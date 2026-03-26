/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:42 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 14:05:43 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

long	ft_strtol(const char *str, char **endptr, int *error);
int		parse_int(const char *str, int *out);

#endif
