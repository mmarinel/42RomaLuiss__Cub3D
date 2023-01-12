/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:40:38 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 18:32:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef M_PI
#  define M_PI		3.14159265358979323846	/* pi */
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define COLOR_MIN 0
# define COLOR_MAX 255

# define BOUND_KEYS 13

# define W_INDEX 0
# define A_INDEX 1
# define S_INDEX 2
# define D_INDEX 3
# define SHIFT_INDEX 4
# define UP_INDEX 5
# define DOWN_INDEX 6
# define RIGHT_INDEX 7
# define LEFT_INDEX 8
# define SPACE_INDEX 9
# define E_INDEX 10
# define ENTER_INDEX 11
# define ESC_INDEX 12

//*		66º...vision cone of our player (FOV - field of vision)
# define FOV 1.15191730632f

# define INITIAL_ROT_ANGLE 0.104533f
# define MAX_ROT_ANGLE 0.314159f
# define ROT_ANGLE_INCREMENT 0.025f

# define FLT_PRECISION 6

//*		BONUSES

# define LEVELS 4

# define SUN_FRAMES 19

# define ENEMIES_DEFAULT_COLLISION_RADIUS 2.0f
# define ENEMY_DIE_ANIM_FRAMES 32

# define DOOR_OPENING_DELAY_FRAMES 12

# define ITEM_ANIM_FRAMES 16
# define ITEM_ANIM_FRAME_STEP 8

//*		menus

# define MENU_NEWG 0
# define MENU_EXIT 1

//*		minimap

# define UHD_BAR_HEIGHT 5

# define UHD_HP_VERT_OFFS 0
# define UHD_MANA_VERT_OFFS 10
# define UHD_ITEM_VERT_OFFS 20

# define MMP_OFFSET (15)
# define MMP_WIDTH (500)
# define MMP_HEIGHT (200)
# define MMP_BORDER_WIDTH (10)
# define MMP_TILE_WIDTH (5)

#endif