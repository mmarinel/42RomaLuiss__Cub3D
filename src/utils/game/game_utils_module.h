/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/30 15:26:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_MODULE_H
# define GAME_UTILS_MODULE_H

# include "../../types.h"
# include "game_utils.h"

//*		geometry
t_2d_point		ft_rotate(t_2d_point vector, float ray_angle);

//*		vecotr utils
t_int_2d_point	ft_get_new_int_2dpt(int x, int y);
t_2d_point		ft_get_new_2dpt(float x, float y);
t_2d_matrix		ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2);

//*		math utils
float			ft_vec_norm(t_2d_point vector);
float			ft_dot_product(t_2d_point v, t_2d_point w);
t_2d_point		ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);
float			flt_round(float nbr, size_t dec_places);

//*		coordinates
t_2d_point		ft_get_new_2dpt(float x, float y);

//*		game memory management
// void			ft_game_init( t_game *game_ref, size_t width, size_t height );

//*		debug
void			t_2d_point_print(const t_2d_point *pt, const char *msg);

#endif