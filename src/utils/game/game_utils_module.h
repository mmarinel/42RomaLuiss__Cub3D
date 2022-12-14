/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/13 19:16:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_MODULE_H
# define GAME_UTILS_MODULE_H

# include "../../types.h"
# include "game_utils.h"

//*		geometry
t_2d_point		ft_rotate(t_2d_point vector, float ray_angle);

//*		vecotr utils
t_int_2d_point	ft_get_new_int_2dpt(int x, int y);
t_2d_point		ft_get_new_2dpt(float x, float y);
t_2d_matrix		ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2);

//*							math utils								*//

//*		vector operators
t_2d_point	ft_vec_normalize(t_2d_point vec);
t_2d_point	ft_vec_opposite(t_2d_point vector);
t_2d_point	ft_vec_sum(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_diff(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_prod(t_2d_point vec, float lambda);
float		ft_vec_norm(t_2d_point vector);
float		ft_dot_product(t_2d_point v, t_2d_point w);
t_bool		ft_int_2d_point_equals(
				const t_int_2d_point *p1,
				const t_int_2d_point *p2
			);
t_bool		ft_2d_point_equals(
				const t_2d_point *p1,
				const t_2d_point *p2
			);

//*		matrix operators
t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);

//*		vec misc
t_2d_point	ft_change_magnitude(t_2d_point vec, float new_magnitude);

//*		math
float		flt_round(float nbr, size_t dec_places);

//*		coordinates
t_2d_point		ft_get_new_2dpt(float x, float y);

//*		game memory management
// void			ft_game_init( t_game *game_ref, size_t width, size_t height );

//*		debug
void			t_2d_point_print(const t_2d_point *pt, const char *msg);
void			ft_print_int_2d_point(const char* pt_name, t_int_2d_point pt);

//*		enemies
t_list	*ft_new_enemy_node(t_2d_point pos);
t_enemy	*ft_clone_enemy(const t_enemy *enemy);
t_bool	enemy_equals(const t_enemy *en1, const t_enemy *en2);
t_bool	enemy_pos(const t_enemy *en, const t_2d_point *pos);
t_enemy	*get_enemy(const t_int_2d_point *pos, t_game *game);

#endif