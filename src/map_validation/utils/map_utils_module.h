/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:56:09 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 12:32:17 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_MODULE_H
# define MAP_UTILS_MODULE_H

# include "../map_validation_types.h"

//*		memory
void	ft_free_map( t_tile ***map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );
void	read_texture_attr(char **ref, const char *path);

//*		logic conditions
t_bool	is_map_edge(
			const t_map_holder *map_handle,
			int x, int y
			);
t_bool	is_valid_map_char( char c );
t_bool	map_fields_complete( t_map_holder *map_handle );
t_bool	is_player_found( void );
void	forget_player(void);

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

//*		debug
void	ft_tile_map_print(t_tile **map, size_t rows, size_t columns);

#endif