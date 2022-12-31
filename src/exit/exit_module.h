/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_module.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:42:31 by earendil          #+#    #+#             */
/*   Updated: 2022/12/31 13:31:05 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_MODULE_H
# define EXIT_MODULE_H

# include "../types.h"
# include "../game_types.h"

int		exit_game(t_game *game);
void	clean_game(t_game *game);

#endif