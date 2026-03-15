#ifndef CODEXION_H
# define CODEXION_H

# include "coder.h"
# include "dongle.h"

typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;

typedef struct s_codexion
{
	int			number_of_coders;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;
	t_algorithm	scheduler;

	t_coder		*coders;
	t_dongle	*dongles;
}	t_codexion;


#endif