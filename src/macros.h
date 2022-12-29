/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:40:38 by earendil          #+#    #+#             */
/*   Updated: 2022/12/29 12:57:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef BONUS
#  define BONUS 0
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

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

//*		minimap

# define UHD_BAR_HEIGHT 5

# define UHD_HP_VERT_OFFS (0					+	0 * UHD_BAR_HEIGHT)
# define UHD_MANA_VERT_OFFS (UHD_HP_VERT_OFFS	+	2 * UHD_BAR_HEIGHT)
# define UHD_ITEM_VERT_OFFS (UHD_MANA_VERT_OFFS	+	2 * UHD_BAR_HEIGHT)

# define MMP_OFFSET (15)
# define MMP_WIDTH (500)
# define MMP_HEIGHT (200)
# define MMP_BORDER_WIDTH (10)
# define MMP_TILE_WIDTH (5)


#endif