/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:25 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 17:47:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "codexion.h"
#include "coder.h"

int	free_coders(t_sim *sim)
{
	if (!sim->coders)
		return (0);
	
	free(sim->coders);

	sim->coders = NULL;
	return (0);
}
