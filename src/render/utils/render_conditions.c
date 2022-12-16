/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:23:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 23:34:47 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_render.h"

t_bool	ft_iscolor( long long red, long long green, long long blue )
{
	return (
		COLOR_MIN <= red && red <= COLOR_MAX
		&& COLOR_MIN <= green && green <= COLOR_MAX
		&& COLOR_MIN <= blue && blue <= COLOR_MAX
	);
}
