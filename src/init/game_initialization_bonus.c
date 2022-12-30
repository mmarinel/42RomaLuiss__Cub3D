/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:34 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 18:29:14 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"
#include <time.h>

void	set_rand(void)
{
	if (BONUS)
		srand(time(NULL));
}
