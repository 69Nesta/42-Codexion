/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:02 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/23 17:53:02 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "codexion.h"
#include "colors.h"
#include "args.h"
#include "logger.h"


int ft_check_missing(int argc)
{
	const char	*args[] = {
		"number_of_coders", "time_to_burnout", "time_to_compile",
		"time_to_debug", "time_to_refactor", "number_of_compiles_required",
		"dongle_cooldown", "scheduler", 0
	};
	int			agrs_index;

	if (argc == ARGS_REQUIRED + 1)
		return (0);
	if (argc > ARGS_REQUIRED + 1)
	{
		error("Too many arguments provided.\n");
		return (1);
	}
	error("Invalid number of arguments.\n");
	error("Missing:");
	agrs_index = argc - 1;
	while (args[agrs_index] && agrs_index < ARGS_REQUIRED)
	{
		printf("\n - %s", args[agrs_index]);
		agrs_index++;
	}
	printf("\n");
	return (1);
}

int ft_check_fill(t_sim *settings, int argc, char **argv)
{
	const int	error = ft_fill_settings(settings, argc, argv);
	const char	*args[] = {
		"Invalid number of coders (must be an integer)",
		"Invalid time to burnout (must be an integer)",
		"Invalid time to compile (must be an integer)",
		"Invalid time to debug (must be an integer)",
		"Invalid time to refactor (must be an integer)",
		"Invalid number of compiles required (must be an integer)",
		"Invalid dongle cooldown (must be an integer)",
		"Invalid scheduler (must be 'fifo' or 'edf')",
		0
	};
	if (error == 0)
		return (0);

	if (error > 0 && error < ARGS_REQUIRED)
	{
		printf("%sError:%s %s\n", RED, CRESET, args[error]);
	}
	else
	{
		printf("%sError:%s Invalid argument format.\n", RED, CRESET);
	}
	return (1);
}

int check_content(t_sim *settings)
{
	const int	check = ft_check_settings(settings);
	const char	*args[] = {
		"Invalid number of coders (must be > 0)",
		"Invalid time to burnout (must be > 0)",
		"Invalid time to compile (must be > 0)",
		"Invalid time to debug (must be > 0)",
		"Invalid time to refactor (must be > 0)",
		"Invalid number of compiles required (must be > 0)",
		"Invalid dongle cooldown (must be > 0)",
		"Invalid scheduler (must be 'fifo' or 'edf')",
		"Too many coders (must be <= 200)",
		0
	};

	if (check != -1)
	{
		printf("%sError:%s %s\n", RED, CRESET, args[check]);
		return (1);
	}

	return (0);
}

int ft_check_args(t_sim *settings, int argc, char **argv)
{
	if (ft_check_missing(argc))
		return (1);
	if (ft_check_fill(settings, argc, argv) != 0)
		return (1);
	if (check_content(settings) != 0)
		return (1);
	return (0);
}
