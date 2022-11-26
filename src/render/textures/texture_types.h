/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:33:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/26 16:35:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_TYPES_H
# define TEXTURE_TYPES_H

# include "../../types.h"

typedef struct s_px_row 
{
	t_int_2d_point	c0;
	t_int_2d_point	c1;
	t_int_2d_point	c2;
	t_int_2d_point	c3;
}	t_px_row;

#endif