#ifndef CODER_H
# define CODER_H

# include <pthread.h>

typedef enum e_coder_state
{
	IDLE,
	COMPILE,
	DEBUG,
	REFACTOR,
	BURNOUT
}	t_coder_state;


typedef enum e_action
{
	TAKE_DONGLE_ACTION,
	COMPILE_ACTION,
	DEBUG_ACTION,
	REFACTOR_ACTION,
	BURNOUT_ACTION
}	t_action;


typedef struct s_coder
{
	int				id;
	t_coder_state	state;
	int				compiles_done;
	int				last_compile_time;
	pthread_t		thread;

}	t_coder;

#endif