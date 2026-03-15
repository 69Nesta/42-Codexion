#include <stdlib.h>
#include <string.h>
#include "codexion.h"
#include "utils.h"

int		ft_fill_settings(t_codexion *settings, int argc, char **argv)
{
	int	*to_fill_int[] = {
		&settings->number_of_coders, &settings->time_to_burnout,
		&settings->time_to_compile, &settings->time_to_debug,
		&settings->time_to_refactor, &settings->number_of_compiles_required,
		&settings->dongle_cooldown, 0
	};
	int	index;

	if (argc != 9)
		return (1);

	index = 0;
	while (to_fill_int[index])
	{
		if (!parse_int(argv[index + 1], to_fill_int[index]))
			return (index);
		index++;
	}
	if (strcmp(argv[8], "fifo") == 0)
		settings->scheduler = FIFO;
	else if (strcmp(argv[8], "edf") == 0)
		settings->scheduler = EDF;
	return (0);
}

int		ft_check_settings(t_codexion *settings)
{
	int args_checker[] = {
		settings->number_of_coders <= 0, settings->time_to_burnout <= 0,
		settings->time_to_compile < 0, settings->time_to_debug < 0,
		settings->time_to_refactor < 0,
		settings->number_of_compiles_required <= 0,
		settings->dongle_cooldown < 0,
		settings->scheduler != FIFO && settings->scheduler != EDF,
		-1
	};
	int	index;

	index = 0;
	while (args_checker[index] != -1)
	{
		if (args_checker[index])
			return (index);
		index++;
	}

	return (0);
}
