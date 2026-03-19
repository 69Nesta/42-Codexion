#ifndef CODEXION_H
# define CODEXION_H

# include "utils.h"
# include "coder.h"
# include "dongle.h"

typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;

typedef struct s_coder t_coder;
typedef struct s_dongle t_dongle;

typedef enum s_sim_state
{
	SIM_WAITING,
	SIM_RUNNING,
	SIM_FAIL
}	t_sim_state;

typedef struct s_sim
{
	int				number_of_coders;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	t_algorithm		scheduler;

	t_bool			stop;
	t_coder			*coders;
	t_dongle		*dongles;
	t_coder			**queue;
	pthread_mutex_t	m_queue;
	pthread_mutex_t	m_log;

	t_sim_state		state;
	pthread_mutex_t	m_state;
	pthread_cond_t	c_state;
}	t_sim;

typedef struct s_dongle
{
	int				id;
	t_bool			taken;
	int				last_use_time;
	t_sim			*sim;
	pthread_mutex_t	mutex;
}	t_dongle;


typedef struct s_coder
{
	int				id;
	t_coder_state	state;
	int				compiles_done;
	int				last_compile_time;
	int				last_state_time;
	int				right_dongle;
	int				left_dongle;
	t_sim			*sim;
	pthread_t		thread;
}	t_coder;


int		create_coders(t_sim *sim);
int		free_coders(t_sim *sim);

int 	create_dongles(t_sim *sim);
int		free_dongles(t_sim *sim);

int		create_coders_queue(t_sim *sim);
int		free_coders_queue(t_sim *sim);

int		create_coders_thread(t_sim *sim);
int		join_coders_thread(t_sim *sim);

void	*coder_routine(void* arg);

int		set_sim_state(t_sim *sim, t_sim_state state);
int		init_simulation(t_sim *sim);
int 	run_simulation(t_sim *sim);
int 	cleanup_simulation(t_sim *sim, int index);


#endif
