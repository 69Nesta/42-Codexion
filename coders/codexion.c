/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:24 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 19:11:17 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "args.h"
#include "logger.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	sim.stop = 0;
	if (ft_check_args(&sim, argc, argv))
		return (1);
	if (!init_simulation(&sim))
		return (error("Something append during initalization !\n"));
	run_simulation(&sim);
	join_monitor_thread(&sim);
	join_coders_thread(&sim);
	cleanup_simulation(&sim, 0);
	return (0);
}
