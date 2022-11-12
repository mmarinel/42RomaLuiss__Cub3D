/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fl_module.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:39 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 10:44:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TYPES_H
# define T_TYPES_H

# include "../../types.h"

//*		"constructor"
t_fl	t_fl_new(float val);

//*		arithmetic
void	t_fl_sum(t_fl a, t_fl b);
void	t_fl_diff(t_fl a, t_fl b);
void	t_fl_mult(t_fl a, t_fl b);
void	t_fl_div(t_fl a, t_fl b);

//*		comparisons
float	t_fl_cmp(t_fl a, t_fl b);

//*		math
t_fl	t_fl_abs(t_fl fl);

//*		debug
void	ft_print_t_fl(t_fl var);

#endif