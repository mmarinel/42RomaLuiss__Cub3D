/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_module.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:32:55 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 18:39:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_MODULE_H
# define LINE_DRAWING_MODULE_H

# include <unistd.h>

# include "line_drawing_types.h"
# include "../render.h"

void	bresenham_algo(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data, t_px_row row);

#endif