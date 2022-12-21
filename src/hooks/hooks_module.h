/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_module.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:15:46 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:30:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_MODULE_H
# define HOOKS_MODULE_H

# include "../types.h"
# include "../game_types.h"

//*		loop
int	loop_hook(t_game *game);

//*		keys
int	key_press_hook(int key_code, t_game *game);
int	key_release_hook(int key_code, t_game *game);

//*		window lose/gain focus
int	enter_window(t_game *game);
int	leave_window(t_game *game);

#endif