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
	
	int				dongles_availables;
	pthread_cond_t	c_dongles_availables;

	t_sim_state		state;
	pthread_mutex_t	m_state;
	pthread_cond_t	c_state;
}	t_sim;

typedef struct s_dongle
{
	int				id;
	t_bool			taken;
	long			last_use_time;
	t_sim			*sim;
	pthread_mutex_t	mutex;
}	t_dongle;


typedef struct s_coder
{
	int				id;
	t_coder_state	state;
	int				compiles_done;
	long			last_compile_time;
	// int				last_state_time;
	t_dongle		*right_dongle;
	t_dongle		*left_dongle;
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

void	*coder_core(void* arg);
int		start_coder_routine(t_sim *sim, t_coder *coder);

int		set_sim_state(t_sim *sim, t_sim_state state);
int		init_simulation(t_sim *sim);
int 	run_simulation(t_sim *sim);
int 	cleanup_simulation(t_sim *sim, int index);

int		start_compiling(t_sim *sim, t_coder *coder);
int		start_debugging(t_sim *sim, t_coder *coder);
int		start_refactoring(t_sim *sim, t_coder *coder);

int		wait_for_dongles(t_sim *sim, t_coder *coder);
int		release_dongle(t_dongle *dongle);
int		release_dongles(t_sim *sim, t_coder *coder);
int		dongle_can_be_used(t_sim *sim, t_dongle *dongle);

int		register_coder_to_queue(t_sim *sim, t_coder *coder);
int		remove_coder_from_queue(t_sim *sim, t_coder *coder);

#endif
