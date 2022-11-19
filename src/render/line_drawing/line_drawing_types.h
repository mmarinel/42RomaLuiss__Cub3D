/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_types.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:28 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 15:54:19 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_TYPES_H
# define LINE_DRAWING_TYPES_H

/**
 * @brief e_BRES_LOW: for line with m < 1
 * where y = mx + q is the line equation;
 * BRES_HIGH: the same, but with m >= 1
 */
typedef enum e_bres_line_type
{
	e_BRES_LOW = 0,
	e_BRES_HIGH = 1,
}	t_bres_line_type;

#endif