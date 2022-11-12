/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flt_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:12:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 12:55:57 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_flt_abs(float val)
{
	if (val >= 0 || isinf(val) || isnan(val))
		return (val);
	else
		return ((-1) * val);
}
