#ifndef UTILS_H
# define UTILS_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

long	ft_strtol(const char *str, char **endptr, int *error);
int		parse_int(const char *str, int *out);

#endif
