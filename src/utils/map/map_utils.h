/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:26 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/03 17:46:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "../../types.h"
# include "../libft/libft_module.h"

//*		memory
void	ft_free_map( t_tile*** map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );

//*		logic conditions
t_bool	is_valid_map_char( char c );
t_bool	is_player_found( void );

//*		characters conditions
t_bool	is_player_map_char( char c );
t_bool	is_floor_map_char( char c );
t_bool	is_wall_map_char( char c );
t_bool	is_empty_map_char( char c );

#endif