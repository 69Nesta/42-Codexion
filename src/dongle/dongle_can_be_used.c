#include "codexion.h"
#include "time.h"


int	dongle_can_be_used(t_sim *sim, t_dongle *dongle)
{
	return (
		!dongle->taken &&
		dongle->last_use_time + sim->time_to_compile + sim->dongle_cooldown <=
		get_timestamp()
	);
}
