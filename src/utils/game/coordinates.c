/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:50:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 13:00:56 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_get_new_2dpt(double x, double y)
{
	t_2d_point	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}
