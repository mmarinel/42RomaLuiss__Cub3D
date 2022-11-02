/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:56:09 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/02 09:14:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_MODULE_H
# define MAP_UTILS_MODULE_H

# include "../../types.h"

//*		memory
void	ft_free_map( t_tile*** map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );

//*		conditions
t_bool	is_valid_map_char( char c );
t_bool	is_player_map_char( char c );
t_bool	is_floor_map_char( char c );
t_bool	is_wall_map_char( char c );
t_bool	is_empty_map_char( char c );

#endif