/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:58:19 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:20:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_iscolor( long long red, long long green, long long blue )
{
	return (
		0 <= red && red <= 255
		&& 0 <= green && green <= 255
		&& 0 <= blue && blue <= 255
	);
}
