/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_module.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:42:31 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:04:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_MODULE_H
# define EXIT_MODULE_H

# include "../basic_types.h"
# include "../game_types.h"

int		exit_game(t_game *game);
void	clean_game(t_game *game);

#endif