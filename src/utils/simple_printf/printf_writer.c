/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:45:34 by earendil          #+#    #+#             */
/*   Updated: 2022/10/26 18:45:47 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_write(const char *c, int *count)
{
	write(STDOUT_FILENO, c, sizeof(char));
	*count = *count + 1;
}
