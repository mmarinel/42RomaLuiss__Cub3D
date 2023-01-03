/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_shift_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:48:36 by earendil          #+#    #+#             */
/*   Updated: 2023/01/03 01:27:45 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_keys_bonus.h"

static void		set_ampl(t_game *game);
static void		reset_ampl(t_game *game);
static size_t	frame_holder(t_bool reset);
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
	const float		mana_cost = game->player.mana / 32.0f;

	game->player.running = e_true;
	game->player.mana -= mana_cost;
	frame = frame_holder(e_false);
	game->player.step_ampl = game->player.acceleration * frame;
}

static void	reset_ampl(t_game *game)
{
	game->player.running = e_false;
	game->player.step_ampl = 0;
	frame_holder(e_true);
}

static size_t	frame_holder(t_bool reset)
{
	static size_t	frame = 0;
	const float		avg_frames_per_sec = 8.0f;

	if (reset)
		frame = 0;
	else if (frame < 2 * avg_frames_per_sec)
		frame += 1;
	return (frame);
}
