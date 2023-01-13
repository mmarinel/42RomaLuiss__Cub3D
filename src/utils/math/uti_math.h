/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:29:56 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:44:02 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTI_MATH_H
# define UTI_MATH_H

# include "../../includes/macros.h"
# include "../../includes/colors.h"

# include "uti_math_types.h"
# include "../../includes/basic_types.h"

# include "../../includes/sys_includes.h"

//*				basic math
float			flt_round(float nbr, size_t dec_places);

//*				creation
t_2d_matrix		ft_get_new_2dmtrx(t_2d_point row_1, t_2d_point row_2);
t_2d_point		ft_get_new_2dpt(float x, float y);
t_int_2d_point	ft_get_new_int_2dpt(int x, int y);
t_2d_matrix		ft_get_new_2dmtrx(t_2d_point row_1, t_2d_point row_2);
t_int_2d_point	as_int_2dpt(const t_2d_point *pt);

//*				vectorial operations
t_2d_point		ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);
float			ft_dot_product(t_2d_point vec_1, t_2d_point vec_2);
float			ft_vec_norm(t_2d_point vector);
t_2d_point		ft_vec_opposite(t_2d_point vector);
t_2d_point		ft_vec_sum(t_2d_point v1, t_2d_point v2);
t_2d_point		ft_vec_diff(t_2d_point v1, t_2d_point v2);
t_2d_point		ft_vec_prod(t_2d_point vec, float lambda);

//*				geometry
t_2d_point		ft_rotate(t_2d_point vector, float ray_angle);

//*				vectors manipulation
t_2d_point		ft_vec_normalize(t_2d_point vec);
t_2d_point		ft_change_magnitude(t_2d_point vec, float new_magnitude);

//*				cmps
t_bool			ft_2d_point_equals(
					const t_2d_point *p1,
					const t_2d_point *p2
					);
t_bool			ft_int_2d_point_equals(
					const t_int_2d_point *p1,
					const t_int_2d_point *p2
					);

//*				vec debug
void			t_2d_point_print(const t_2d_point *pt, const char *msg);

#endif