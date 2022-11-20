/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_decision_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:43:15 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/20 12:31:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

int	bres_decision_var_initial(
		const size_t norm_delta_x,
		const size_t norm_delta_y,
		t_bres_line_type bres_type
	)
{
	if (e_BRES_LOW_POS == bres_type || e_BRES_LOW_NEG == bres_type)
		return (2 * norm_delta_y - norm_delta_x);
	else
		return (norm_delta_y - 2 * norm_delta_x);
}

int	bres_update_decision_var(t_bres_line_type bres_type, int d_k,
				const size_t delta_x, const size_t delta_y)
{
	if (e_BRES_LOW_POS == bres_type || e_BRES_LOW_NEG == bres_type)
	{
		if (d_k >= 0)
			d_k += (2 * (delta_y  - delta_x));
		else
			d_k += (2 * delta_y);
		return (d_k);
	}
	else
	{
		if (d_k >= 0)
			d_k -= (2 * delta_x);
		else
			d_k -= (2 * (delta_x  - delta_y));
		return (d_k);
	}
}
