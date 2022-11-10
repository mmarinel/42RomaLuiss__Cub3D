/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:26 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 08:26:28 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "../../types.h"
# include "../../colors.h"
# include "../libft/libft_module.h"

# include <stdio.h>

//*		memory
void	ft_free_map( t_tile ***map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );

//*		logic conditions
t_bool	is_valid_map_char( char c );
t_bool	is_player_found( void );

//*		characters conditions
t_bool	is_player_map_char( char c );
t_bool	is_floor_map_char( char c );
t_bool	is_wall_map_char( char c );
t_bool	is_empty_map_char( char c );

//*		attrs id conditions
t_bool	is_attrs_char( const char *id );
t_bool	is_attrs_player_dir_char( const char *id );
t_bool	is_attrs_color_field_char( const char *id );
t_bool	is_floor_color_id( const char *id );
t_bool	is_ceiling_color_id( const char *id );

//*		t_tile map utils
void	ft_trim_map(t_map_holder *map_handle, t_bool *err_flag);

#endif