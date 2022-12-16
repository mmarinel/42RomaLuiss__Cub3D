/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti_math_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:31:46 by earendil          #+#    #+#             */
/*   Updated: 2022/12/16 22:53:13 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTI_MATH_TYPES_H
# define UTI_MATH_TYPES_H

typedef struct s_int_2Dpoint
{
	int	x;
	int	y;
}	t_int_2d_point;

typedef struct s_2Dpoint
{
	float	x;
	float	y;
}	t_2d_point;

typedef struct s_2Dmatrix
{
	t_2d_point	row_1;
	t_2d_point	row_2;
}	t_2d_matrix;

#endif