/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_types.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:04:08 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:04:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_TYPES_H
# define FIXED_POINT_TYPES_H

# include "../../types.h"

typedef struct s_fixed		t_fixed;
typedef struct s_fixed_val	t_fixed_val;

typedef enum e_fixed_frac_bits
{
	e_8_BITS_FIXED = 8,
	e_16_BITS_FIXED = 16,
	e_32_BITS_FIXED = 32,
	e_63_BITS_FIXED = 63,
}	t_fixed_frac_bits;

struct s_fixed_val
{
	int32_t				row_bits;
	t_fixed_frac_bits	frac_bits;
	t_bool				inf;
	t_bool				neg_inf;
};

//*		conversions
typedef struct s_fixed_to_dbl_closure
{
	t_fixed_val	val;
	double(*call)(struct s_fixed this);
}	t_fixed_to_dbl;

typedef struct s_fixed_to_int_closure
{
	t_fixed_val	val;
	int(*call)(struct s_fixed this);
}	t_fixed_to_int;

//*		arithmetic
typedef struct s_fixed_sum_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_sum;

typedef struct s_fixed_diff_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_diff;

typedef struct s_fixed_mult_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_mult;

typedef struct s_fixed_div_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_div;

typedef struct s_fixed_cmp_closure
{
	t_fixed_val	val;
	double(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_cmp;

typedef struct s_fixed_print_closure
{
	t_fixed_val	val;
	void(*call)(struct s_fixed this);
}	t_fixed_print;

struct s_fixed
{
	t_fixed_val		fixed_val;
	t_fixed_to_dbl	to_double;
	t_fixed_to_int	to_int;
	t_fixed_sum		sum;
	t_fixed_diff	diff;
	t_fixed_mult	mult;
	t_fixed_div		div;
	t_fixed_cmp		cmp;
	t_fixed_print	print;
};

#endif