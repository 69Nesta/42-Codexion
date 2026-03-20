#include "codexion.h"
#include "time.h"


int	release_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->taken = FALSE;
	dongle->last_use_time = get_timestamp();
	pthread_mutex_unlock(&dongle->mutex);
	return (1);
}
