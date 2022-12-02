/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/02 16:12:39 by mmarinel         ###   ########.fr       */
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

//*							math utils								*//

//*		vector operators
t_2d_point	ft_vec_normalize(t_2d_point vec);
t_2d_point	ft_vec_opposite(t_2d_point vector);
t_2d_point	ft_vec_sum(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_diff(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_prod(t_2d_point vec, float lambda);
float		ft_vec_norm(t_2d_point vector);
float		ft_dot_product(t_2d_point v, t_2d_point w);

//*		matrix operators
t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);

//*		vec misc
t_2d_point	ft_change_magnitude(t_2d_point vec, float new_magnitude);

//*		math
float		flt_round(float nbr, size_t dec_places);

//*		coordinates
t_2d_point		ft_get_new_2dpt(float x, float y);

//*		game memory management
// void			ft_game_init( t_game *game_ref, size_t width, size_t height );

//*		debug
void			t_2d_point_print(const t_2d_point *pt, const char *msg);

#endif