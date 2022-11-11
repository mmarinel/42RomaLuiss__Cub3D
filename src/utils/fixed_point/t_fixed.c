/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fixed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 15:13:30 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

t_fixed	t_fixed_new(double val)
{
	t_fixed	fixed_new;

	fixed_new.frac_bits = e_8_BITS_FIXED;
	fixed_new.row_bits
		= fix_round(val * (1 << fixed_new.frac_bits));
	fixed_new.inf = e_false;
	fixed_new.neg_inf = e_false;
	return (fixed_new);
}
