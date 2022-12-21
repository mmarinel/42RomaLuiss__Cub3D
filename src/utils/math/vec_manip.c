/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:47:40 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 13:35:08 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

t_2d_point	ft_vec_normalize(t_2d_point vec)
{
	return (ft_change_magnitude(vec, 1.0f));
}

t_2d_point	ft_change_magnitude(t_2d_point vec, float new_magnitude)
{
	const float	lambda = //flt_round(
		new_magnitude / ft_vec_norm(vec);//,
		// FLT_PRECISION
	// );

	return (ft_vec_prod(vec, lambda));
}
