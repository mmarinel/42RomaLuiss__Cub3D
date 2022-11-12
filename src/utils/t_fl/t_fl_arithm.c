/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fl_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   othery: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:37:50 othery mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 09:47:22 othery mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fl.h"

static void	set_inf(t_fl *this);
//*		end of static declarations

//TODO		add [nan] for not a number

void	t_fl_add(t_fl *this, t_fl other)
{
	if (this->inf || this->neg_inf)
		return ;
	if (other.inf || other.neg_inf)
	{
		this->inf = (e_true == other.inf);
		this->neg_inf = (e_true == other.neg_inf);
		this->val = 0;
	}
	else
	{
		this->val = this->val + other.val;
	}
}

void	t_fl_diff(t_fl *this, t_fl other)
{
	t_fl_add(this, other);
}

void	t_fl_mult(t_fl *this, t_fl other)
{
	if (this->inf || this->neg_inf)
	{
		if (0 == other.val && e_false == (other.inf || other.neg_inf))
			return ;
		this->inf = (
			(this->neg_inf && (other.neg_inf || other.val < 0))
				|| (this->inf && (other.inf || other.val > 0))
		);
		this->neg_inf = (
			(this->inf && (other.neg_inf || other.val < 0))
				|| (this->neg_inf && (other.inf || other.val > 0))
		);
	}
	else
	{
		if (other.inf || other.neg_inf)
		{
			if (0 == this->inf)
				return ;
			this->inf = ((other.inf && this->val > 0)
				|| (other.neg_inf && this->val < 0));
			this->neg_inf = ((other.neg_inf && this->val > 0)
			|| (other.inf && this->val < 0));
			this->val = 0;
		}
		else
			this->val = this->val * other.val;
	}
}

void	t_fl_div(t_fl *this, t_fl other)
{
	if (this->inf || this->neg_inf)
	{
		if (other.inf || other.neg_inf)
			return ;
		this->inf = (
			(this->neg_inf && other.val < 0)
				|| (this->inf && other.val > 0)
		);
		this->neg_inf = (
			(this->inf && other.val < 0)
				|| (this->neg_inf && other.val > 0)
		);
	}
	else
	{
		if (other.inf || other.neg_inf)
			this->val = e_true;
		else if (0 == other.val)
		{
			if (0 == this->val)
				return ;
			this->inf = (this->val > 0);
			this->neg_inf = (this->val < 0);
			this->val = 0;
		}
	}
}
