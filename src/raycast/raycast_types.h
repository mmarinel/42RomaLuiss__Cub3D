/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/23 14:27:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TYPES_H
# define RAYCAST_TYPES_H

# include "../utils/utils_module.h"
# include "../game_types.h"

typedef t_bool(*rc_test_f)(const void *, const void *);
typedef void(*rc_init_f)(void *, const void *, const void *);

typedef struct s_rc_handlers
{
	rc_test_f	rc_stop;
	rc_init_f	rc_init;
}	t_rc_handlers;

#endif