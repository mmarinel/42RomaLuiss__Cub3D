/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:49:33 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 17:44:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_H
# define FIXED_POINT_H

# include "../../types.h"
# include "../../colors.h"

# include <stdio.h>

//*		constructor
t_fixed	t_fixed_new(double val);

//*		conversions
double	t_fixed_to_double( t_fixed this );
int		t_fixed_to_int( t_fixed this );

//*		arithmetic
t_fixed	t_fixed_sum(t_fixed this, t_fixed val);
t_fixed	t_fixed_diff(t_fixed this, t_fixed val);
t_fixed	t_fixed_mult(t_fixed this, t_fixed val);
t_fixed	t_fixed_div(t_fixed this, t_fixed val);

//*		conditions
double	t_fixed_cmp(t_fixed this, t_fixed val);

//*		utils
void	t_fixed_print(t_fixed this);
int32_t	fix_round(double val);
t_fixed	t_fixed_abs(t_fixed this);

#endif