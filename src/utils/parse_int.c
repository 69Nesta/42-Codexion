/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:48:15 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/26 13:17:37 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "limits.h"

long	ft_strtol(const char *str, char **endptr, int *error)
{
	long	result;
	int		sign;
	int		new_digit;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		new_digit = (*str - '0');
		if (result * 10 + new_digit < result)
			*error = 1;
		result = result * 10 + new_digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (sign * result);
}

int	parse_int(const char *str, int *out)
{
	char	*endptr;
	int		err;
	long	val;

	val = ft_strtol(str, &endptr, &err);
	if (endptr == str)
		return (0);
	if (*endptr != '\0')
		return (0);
	if ((err != 0) || val > INT_MAX || val < INT_MIN)
		return (0);
	*out = (int) val;
	return (1);
}
