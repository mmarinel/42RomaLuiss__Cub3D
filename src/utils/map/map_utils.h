/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:26 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/02 07:51:56 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "../../types.h"
# include "../libft/libft_module.h"

t_bool	is_valid_map_char( char c );
t_bool	is_player_map_char( char c );
t_bool	is_floor_map_char( char c );
t_bool	is_wall_map_char( char c );

#endif