/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_module.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:23:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:05:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_MODULE_H
# define MAP_VALIDATION_MODULE_H

# include "../types.h"

t_bool	is_valid_map( const char *path, t_map_holder *map_handle );

#endif