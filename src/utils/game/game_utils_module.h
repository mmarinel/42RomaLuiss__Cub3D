/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/24 02:59:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_MODULE_H
# define GAME_UTILS_MODULE_H

# include "../../types.h"
# include "game_utils.h"

//*		player
t_bool	is_free_pos(t_game *g, t_2d_point pt);
t_bool	door_obstacle_through_dir(t_list *spotted_doors, const t_int_2d_point *end_tile);
t_bool	is_traversable_pos(
	t_game *g,
	const t_2d_point *old_pos,
	const t_2d_point *next_pos
	);

//*		map
t_2d_point	map_pos_clip(t_2d_point pt, t_game *game);
t_bool		is_map_pos(
	const t_map_holder *map_handle,
	const t_int_2d_point *pos
	);
t_bool		is_door_map_char( char c );
t_bool		is_enemy_map_char( char c );

//*		geometry
t_2d_point		ft_rotate(t_2d_point vector, float ray_angle);

//*		vecotr utils
t_int_2d_point	ft_get_new_int_2dpt(int x, int y);
t_2d_point		ft_get_new_2dpt(float x, float y);
t_2d_matrix		ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2);

//*							math utils								*//

//*		vector operators
t_2d_point		ft_vec_normalize(t_2d_point vec);
t_2d_point		ft_vec_opposite(t_2d_point vector);
t_2d_point		ft_vec_sum(t_2d_point v1, t_2d_point v2);
t_2d_point		ft_vec_diff(t_2d_point v1, t_2d_point v2);
t_2d_point		ft_vec_prod(t_2d_point vec, float lambda);
float			ft_vec_norm(t_2d_point vector);
float			ft_dot_product(t_2d_point v, t_2d_point w);
t_bool			ft_int_2d_point_equals(
					const t_int_2d_point *p1,
					const t_int_2d_point *p2
				);
t_bool			ft_2d_point_equals(
					const t_2d_point *p1,
					const t_2d_point *p2
				);

//*		matrix operators
t_2d_point		ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);

//*		vec misc
t_int_2d_point	as_int_2dpt(const t_2d_point *pt);
t_2d_point		ft_change_magnitude(t_2d_point vec, float new_magnitude);

//*		math
float			flt_round(float nbr, size_t dec_places);

//*		coordinates
t_2d_point		ft_get_new_2dpt(float x, float y);

//*		debug
void			t_2d_point_print(const t_2d_point *pt, const char *msg);
void			ft_print_int_2d_point(const char* pt_name, t_int_2d_point pt);

				//*			
				//*			BONUS
				//*			

//*		enemies
t_bool			is_free_pos_for_en(t_game *g, t_2d_point pt, t_enemy *enemy);
t_bool			enemy_aggro(const void *enemy, const void *game);
t_bool			enemy_colliding(const void *enemy, const void *pos);
t_list			*ft_new_enemy_node(const t_2d_point *pos);
t_enemy			*ft_clone_enemy(const t_enemy *enemy);
t_bool			enemy_equals(const t_enemy *en1, const t_enemy *en2);
t_bool			enemy_pos(const void *en, const void *pos);
t_enemy			*get_enemy(const t_int_2d_point *pos, t_game *game);

//*		doors
t_list	*ft_new_door_node(t_int_2d_point pos, t_tile type);
t_bool	door_front_side(t_tile door_type, t_side side);
t_bool	door_pos(const void *door, const void *pos);
t_bool	is_spotted_door_valicable_in_tile(const void *door, const void *end_tile);
t_bool	is_spotted_door_valicable(const void *door, const void *_);
t_bool	is_spotted_door_invalicable(const void *door, const void *_);

//*		sun
int	west_axis_angle_to_px_shift(t_game *g);
int	west_middle_point_dist_to_px_shift(t_game *g);

#endif