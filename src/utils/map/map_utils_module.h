/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:56:09 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/01 10:15:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_MODULE_H
# define MAP_UTILS_MODULE_H

# include "../../types.h"

void	ft_free_map( t_tile*** map_ref, size_t rows );
t_tile	**ft_map_init( size_t rows, size_t columns );

#endif