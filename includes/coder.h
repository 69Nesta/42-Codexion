/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:05:26 by rpetit            #+#    #+#             */
/*   Updated: 2026/03/24 14:06:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_H
# define CODER_H

# include <stddef.h> 
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

#endif
