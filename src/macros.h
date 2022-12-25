/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:40:38 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 01:41:53 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef BONUS
#  define BONUS 0
# endif

//*		66º...vision cone of our player (FOV - field of vision)
# define FOV ( (11.0f / 30.0f) * M_PI )

# define INITIAL_ROT_ANGLE 0.104533f
# define MAX_ROT_ANGLE 0.314159f
# define ROT_ANGLE_INCREMENT 0.025f

# define SUN_FRAMES 19

# define ENEMY_DIE_ANIM_FRAMES 48

# define DOOR_OPENING_DELAY_FRAMES 12

# define ITEM_BOUNCING_PX_SHIFT 4
# define ITEM_BOUNCING_MAX_SHIFT 16

# define UHD_BAR_HEIGHT 5

# define FLT_PRECISION 6

#endif