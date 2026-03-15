#ifndef ARGS_H
# define ARGS_H

# include "codexion.h"
# define ARGS_REQUIRED	8

int	ft_fill_settings(t_codexion *settings, int argc, char **argv);
int	ft_check_settings(t_codexion *settings);
int ft_check_args(t_codexion *settings, int argc, char **argv);

#endif