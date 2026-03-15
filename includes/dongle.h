#ifndef DONGLE_H
# define DONGLE_H

# include <pthread.h>
# include "utils.h"

typedef struct s_dongle
{
	t_bool			taken;
	int				last_use_time;
	pthread_mutex_t	mutex;
}	t_dongle;

#endif