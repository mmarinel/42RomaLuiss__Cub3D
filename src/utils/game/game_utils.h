/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 12:07:09 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

# include "../../basic_types.h"
# include "../../game_types.h"
# include "../../raycast/raycast_types.h"
// # include "../../init/game_init_types.h"
// # include "../../map_validation/map_validation_types.h"
// # include "../../raycast/raycast_types.h"
// # include "../../render/render_types.h"
# include "../../colors.h"

# include "../../raycast/raycast_module.h"
# include "../libft/libft_module.h"
# include "../utils_module.h"

# include "../../sys_includes.h"

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
t_bool		is_item_map_char( char c );

//*		keys
t_bool	is_movement_key(t_key_state *key);
t_bool	is_rotation_key(t_key_state *key);

//*		geometry
t_2d_point	ft_rotate(t_2d_point vector, float ray_angle);

//*		vecotr utils
t_2d_point	ft_get_new_2dpt(float x, float y);
t_2d_matrix	ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2);
t_bool		ft_2d_point_equals(const t_2d_point *p1, const t_2d_point *p2);

//*		math utils
t_2d_point	ft_vec_opposite(t_2d_point vector);
t_2d_point	ft_vec_sum(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_diff(t_2d_point v1, t_2d_point v2);
t_2d_point	ft_vec_prod(t_2d_point vec, float lambda);
t_2d_point	ft_change_magnitude(t_2d_point vec, float new_magnitude);
float		ft_dot_product(t_2d_point v, t_2d_point w);
t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector);
float		flt_round(float nbr, size_t dec_places);

//*		utils
void	ft_print_2d_point(const char* pt_name, t_2d_point pt);

//*				BONUS
//*				
//*				

//*		doors
t_bool	door_front_side(t_tile door_type, t_side side);
t_bool	door_pos(const void *door, const void *pos);
t_bool	is_spotted_door_valicable_in_tile(const void *door, const void *end_tile);
t_bool	is_spotted_door_valicable(const void *door, const void *_);
t_bool	is_spotted_door_invalicable(const void *door, const void *_);

//*		items
t_list	*ft_new_item_node(const t_2d_point *pos);
t_item	*get_item(const t_int_2d_point *pos, t_game *game);
t_bool	item_pos(const void *item, const void *pos);
t_bool	item_equals(const t_item *item1, const t_item *item2);

//*		enemies
t_bool	enemy_colliding(const void *enemy, const void *pos);

#endif