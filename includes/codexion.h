#ifndef CODEXION_H
# define CODEXION_H

# include "coder.h"
# include "dongle.h"

typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;

typedef struct s_coder t_coder;
typedef struct s_dongle t_dongle;

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

typedef struct s_dongle
{
	int				id;
	t_bool			taken;
	int				last_use_time;
	t_codexion		*codexion;
	pthread_mutex_t	mutex;
}	t_dongle;


typedef struct s_coder
{
	int				id;
	t_coder_state	state;
	int				compiles_done;
	int				last_compile_time;
	int				right_dongle;
	int				left_dongle;
	t_codexion		*codexion;
	pthread_t		thread;
}	t_coder;

typedef struct s_worker
{
	t_codexion	*codexion;
	int			id;
}	t_worker;

int	create_coders(t_codexion *codexion);
int create_dongles(t_codexion *codexion);

int create_threads(t_codexion *codexion);

int	free_coders(t_codexion *codexion);
int free_dongles(t_codexion *codexion);

#endif
