/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_has_finish_compiles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:09:47 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 11:22:02 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	coder_has_finish_compiles(t_sim *sim, t_coder *coder)
{
	return (coder->compiles_done >= sim->number_of_compiles_required);
}
