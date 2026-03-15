#include <stdio.h>
#include "colors.h"
#include "coder.h"
#include "time.h"

int error(char *str)
{
	return (printf("%sERROR:%s %s", RED, CRESET, str));
}

int log_action(int coder_id, t_action action)
{
	const char *action_str[] = {
		[TAKE_DONGLE_ACTION] = "has taken a dongle",
		[COMPILE_ACTION] = "is compiling",
		[DEBUG_ACTION] = "is debugging",
		[REFACTOR_ACTION] = "is refactoring",
		[BURNOUT_ACTION] = "burned out"
	};
	return (
		printf("%d %d %s\n", get_timestamp(), coder_id, action_str[action])
	);
}