#include <unistd.h>
#include <stdio.h>
#include "codexion.h"
#include "logger.h"


int	wait_dongles_cooldown(t_sim *sim, t_coder *coder)
{
	long long left_remaining;
	long long right_remaining;

	left_remaining = 0;
	if (coder->left_dongle->last_use_time != -1)
		left_remaining = sim->dongle_cooldown - (
			get_timestamp() - coder->left_dongle->last_use_time
		);

	right_remaining = 0;
	if (coder->right_dongle->last_use_time != -1)
		right_remaining = sim->dongle_cooldown - (
			get_timestamp() - coder->right_dongle->last_use_time
		);

	// printf("\e[0;33mCoder %d is waiting for dongles cooldown left: %d right: %d | at: %ld | left_remaining: %lld | right_remaining: %lld\n\e[0m", coder->id, coder->left_dongle->id, coder->right_dongle->id, get_timestamp(), left_remaining, right_remaining);
	if (left_remaining > 0 || right_remaining > 0)
		usleep((
			left_remaining  * (left_remaining > right_remaining)
			+ right_remaining * (right_remaining >= left_remaining)
		) * 1000);

	log_action(sim, coder->id, TAKE_DONGLE_ACTION);
	log_action(sim, coder->id, TAKE_DONGLE_ACTION);
	return (1);
}
