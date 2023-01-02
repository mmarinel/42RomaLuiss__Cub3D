/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_shift_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:48:36 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 09:55:40 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_keys_bonus.h"

static void		set_ampl(t_game *game);
static void		reset_ampl(t_game *game);
static size_t	frame_holder(int reset);
//*		end of static declarations

void	in_game_shift_key(t_key_state *key, t_game *game)
{
	if (KeyPress == key->state && game->player.mana > 0)
		set_ampl(game);
	else
		reset_ampl(game);
}

static void	set_ampl(t_game *game)
{
	size_t			frame;
	const float		cost = game->player.mana / 4.0f;
	const float		max_ampl = 4.0f;
	const float		first_ampl = 0.5f;

	game->player.running = e_true;
	game->player.mana -= cost;
	frame = frame_holder(-1);
	if (0 == frame)
	{
		if (0 == game->player.step_ampl)
			game->player.step_ampl = first_ampl;
		else if (game->player.step_ampl < max_ampl)
			game->player.step_ampl *= 2;
	}
	frame_holder(1);
}

static void	reset_ampl(t_game *game)
{
	game->player.running = e_false;
	game->player.step_ampl = 0;
	frame_holder(0);
}

static size_t	frame_holder(int reset)
{
	static size_t	frame = 0;
	const size_t	clock = 4.0f;

	if (0 == reset)
		frame = 0;
	else if (reset > 0)
		frame = (frame + 1) % clock;
	return (frame);
}
