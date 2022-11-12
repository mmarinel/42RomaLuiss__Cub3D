/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 10:27:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

# include "../../types.h"
# include "../../colors.h"
# include "../libft/libft_module.h"

# include <math.h>
# include <stdio.h>
//*		for 'NULL' keyword
# include <stddef.h>

//*		geometry
t_2d_point	ft_rotate(t_2d_point vector, float ray_angle);

//*		vecotr utils
t_2d_point	ft_get_new_2dpt(float x, float y);
t_2d_matrix	ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2);

//*		math utils
float		ft_dot_product(t_2d_point v, t_2d_point w);
t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);

//*		utils
void	ft_print_2d_point(const char* pt_name, t_2d_point pt);

#endif