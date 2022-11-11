/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_module.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:50:04 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 15:37:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_H
# define FIXED_POINT_H

# include "../../types.h"
# include "../../colors.h"

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
t_fixed	t_fixed_abs(t_fixed this);
void	t_fixed_print(t_fixed this);

#endif