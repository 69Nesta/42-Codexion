#ifndef LOGGER_H
# define LOGGER_H

# include "coder.h"
# include "codexion.h"

int		error(char *str);
int		log_action(t_sim *sim, int coder_id, t_action action);

#endif