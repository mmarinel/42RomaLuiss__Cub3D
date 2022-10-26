/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:24:27 by earendil          #+#    #+#             */
/*   Updated: 2022/10/26 18:27:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_put_nbr_base(long long num, const char *base, int base_num)
{
	if (num >= (long long) base_num)
		ft_put_nbr_base(num / base_num, base, base_num);
	ft_write(&base[num % base_num]);
}
