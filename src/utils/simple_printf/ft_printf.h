/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:45:56 by earendil          #+#    #+#             */
/*   Updated: 2022/10/28 08:47:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC_RADIX "0123456789"
# define HEXA_RADIX "0123456789abcdef"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//* user defined exposed functions
int		ft_printf(const char *format_string, ...);

//* printf cases
void	pf_case_str(char *str, int *count);
void	pf_case_int(int n, int *count);
void	pf_case_hexa(long long n, int *count);

//* printf utils
void				pf_write(const char *c, int *count);
void				pf_put_nbr_base(long long num, const char *base,
						int base_num, int *count);
unsigned long long	pf_abs(long long nbr);

#endif