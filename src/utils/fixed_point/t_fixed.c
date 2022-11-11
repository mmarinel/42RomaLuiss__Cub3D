/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fixed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 11:57:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

static int32_t	fix_round(double val);
static void		fix_set_methods(t_fixed *fixed);
//*		end of static declarations

t_fixed	t_fixed_new(double val)
{
	t_fixed	fixed_new;

	fixed_new.fixed_val.frac_bits = e_8_BITS_FIXED;
	fixed_new.fixed_val.row_bits
		= fix_round(val * (1 << fixed_new.fixed_val.frac_bits));
	fixed_new.fixed_val.inf = e_false;
	fixed_new.fixed_val.neg_inf = e_false;
	fix_set_methods(&fixed_new);
	return (fixed_new);
}
