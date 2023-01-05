/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_module.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:23:13 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/05 14:57:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_MODULE_H
# define MAP_VALIDATION_MODULE_H

# include "map_validation_types.h"
# include "../types.h"

t_bool	is_valid_map( const char *path, t_map_holder *map_handle );

#endif