/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_module.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:39 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 12:18:08 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TYPES_H
# define T_TYPES_H

# include "../../types.h"

//*		constructor
t_dbl	t_dbl_new(double val);

//*		arithmetic
t_dbl	t_dbl_sum(t_dbl a, t_dbl b);
t_dbl	t_dbl_diff(t_dbl a, t_dbl b);
t_dbl	t_dbl_mult(t_dbl a, t_dbl b);
t_dbl	t_dbl_div(t_dbl a, t_dbl b);

//*		comparisons
double	t_dbl_cmp(t_dbl a, t_dbl b);

//*		debug
void	ft_print_t_dbl(t_dbl var);

#endif