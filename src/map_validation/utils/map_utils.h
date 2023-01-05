/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:26 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/05 17:42:16 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "../../types.h"
# include "../../utils/math/uti_math_types.h"
# include "../map_validation_types.h"

# include "../../utils/utils_module.h"
# include "../bonus/map_validation_bonus_module.h"

# include "../../sys_includes.h"

//*		memory
void	ft_free_map( t_tile ***map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );

//*		logic conditions
t_bool	is_valid_map_char( char c );
t_bool	is_player_found( void );

//*		attrs id conditions
t_bool	is_attrs_char( const char *id );
t_bool	is_attrs_player_dir_char( const char *id );
t_bool	is_attrs_color_field_char( const char *id );
t_bool	is_floor_color_id( const char *id );
t_bool	is_ceiling_color_id( const char *id );

//*		t_tile map utils
void	ft_trim_map(t_map_holder *map_handle, t_bool *err_flag);

#endif