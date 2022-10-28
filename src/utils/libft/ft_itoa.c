/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:01:41 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/28 09:44:01 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_INT_SIZE 11

static long	ft_itoa_rec(int n, size_t pos, int is_neg, char **result);

char	*ft_itoa(int n)
{
	char	*result;

	if (n == -2147483648)
	{
		result = (char *) malloc((MIN_INT_SIZE + 1) * sizeof(char));
		if (!result)
			return (NULL);
		ft_memcpy(result, "-2147483648", MIN_INT_SIZE + 1);
		return (result);
	}
	if (-1 == ft_itoa_rec(ft_abs(n), n < 0, n < 0, &result))
		return (NULL);
	return (result);
}

static long	ft_itoa_rec(int n, size_t pos, int is_neg, char **result)
{
	long	index;

	if (n < 10)
	{
		*result = (char *) malloc((pos + 2) * sizeof(char));
		if (!(*result))
			return (-1);
		*(*result + (pos + 1)) = '\0';
		index = is_neg;
		if (is_neg)
			*result[0] = '-';
	}
	else
		index = ft_itoa_rec(n / 10, pos + 1, is_neg, result);
	if (-1 == index)
		return (-1);
	*(*result + index) = (n % 10) + 48;
	return (index + 1);
}
