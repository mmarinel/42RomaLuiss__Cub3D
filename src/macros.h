/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:40:38 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 13:52:39 by earendil         ###   ########.fr       */
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

# define FLT_PRECISION 6

//*		BONUSES

# define SUN_FRAMES 19

# define ENEMY_DIE_ANIM_FRAMES 48

# define DOOR_OPENING_DELAY_FRAMES 12

# define ITEM_ANIM_FRAMES 16
# define ITEM_ANIM_FRAME_STEP (ITEM_ANIM_FRAMES / 2)

# define UHD_BAR_HEIGHT 5

#endif