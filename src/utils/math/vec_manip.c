/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:47:40 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:47:26 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

t_2d_point	ft_vec_normalize(t_2d_point vec)
{
	return (ft_change_magnitude(vec, 1.0f));
}

t_2d_point	ft_change_magnitude(t_2d_point vec, float new_magnitude)
{
	const float	lambda
		= new_magnitude / ft_vec_norm(vec);

	return (ft_vec_prod(vec, lambda));
}
