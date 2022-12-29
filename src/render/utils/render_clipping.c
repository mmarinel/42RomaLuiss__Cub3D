/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_clipping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:45:11 by earendil          #+#    #+#             */
/*   Updated: 2022/12/29 12:58:40 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_render_module.h"

t_int_2d_point	endpoint_clip(t_int_2d_point endpoint)
{
	if (endpoint.y < 0)
		endpoint.y = 0;
	else if (endpoint.y >= SCREEN_HEIGHT)
		endpoint.y = SCREEN_HEIGHT - 1;
	
	return (endpoint);
}
