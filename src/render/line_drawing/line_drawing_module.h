/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_module.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:32:55 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 15:35:47 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_MODULE_H
# define LINE_DRAWING_MODULE_H

# include "../render.h"

void	bresenham_high_line(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data);

#endif