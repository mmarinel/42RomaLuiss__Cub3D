/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/21 01:58:11 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void			draw_background(t_game *g);
static void			render_column(
						size_t column,
						t_game *g,
						const t_raycast_return *rc_return
					);
static t_2d_point	ray_dir_for_col(size_t col, t_game *g);
// static t_render_data			render_fetch_data(t_game *g,
// 									float cur_ray_angle);
// static t_wall_camera_incidence	wall_camera_incidence(
// 									t_camera_plane cp, t_side side
// 								);
// static size_t					render_region(t_game *g,
// 									float cur_ray_angle,
// 									size_t *cur_screen_px
// 								);
// static size_t	hit_wall_width(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence);
// static size_t	hit_wall_height(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence);
static void	draw_background_bonus(t_game *g);
static void	draw_sun(t_game *g);
static int	background_next_pixel(t_nxt_px_f_arg *nxt_px_f_arg);

void		render_enemies(
	t_list *enemies,
	t_game *g
	);
void		render_enemy(
	t_rendered_enemy *enemy_data,
	t_game *g
	);
void		enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_enemy *enemy_data,
	t_game *g
	);
t_column_info	enemy_colinfo(
	size_t resized_texture_col,
	size_t enemy_size,
	const t_rendered_enemy *enemy_data,
	t_game *g
	);
void			render_health_bar(t_game *g);
void			render_mana_bar(t_game *g);
void			render_collision(t_game *g);
void			render_attack(t_game *g, t_list *enemies);
void			render_doors(
	const size_t screen_col,
	const t_raycast_return *rc_ret,
	t_game *g
	);
//*		end of static declarations

// int	ln_clipper(t_clip_opcode opcode, size_t size);
// size_t	ln_clip(size_t coordinate);
size_t	get_texture_column(const t_rc_ret_data *rc_ret);
int		nearest_neighbour(t_nxt_px_f_arg *nxt_px_f_arg);
//*																			
//*									DECOMMENTARE 						
//*																			
void	render_next_frame(t_game *g)
{
	size_t				col;
	t_raycast_return	rc_return;
	t_list				*enemies;
	
	mlx_clear_window(g->screen_handle.mlx, g->screen_handle.window);
	(void)draw_background;//* MANDATORY
	draw_background_bonus(g);
	draw_sun(g);
	enemies = NULL;
	col = 0;
	while (col < g->screen_handle.width)
	{
		rc_return = raycast(g, ray_dir_for_col(col, g));
		if (BONUS)
		{
			update_enemy_list(&enemies, &rc_return, col);
		}
		render_column(col, g, &rc_return);
		if (BONUS)
		{
			render_doors(col, &rc_return, g);
		}
		col++;
	}
	render_enemies(enemies, g);
	render_collision(g);
	render_health_bar(g);
	render_mana_bar(g);
	if (g->player.attacking)
		render_attack(g, enemies);
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		g->screen_handle.frame_data.img,
		0, 0);
}

static int	attack_next_px(t_nxt_px_f_arg *arg)
{
	const t_color	color = *(const t_color *)arg->arg;

	return (ft_get_mlx_color(color));
}

static void	draw_laser(
	const t_int_2d_point *endpoint,
	const size_t offset,
	const t_color *laser_color,
	t_game *g
	)
{
	bresenham_plot(
		(t_int_2d_point[2]){
			(t_int_2d_point){
				endpoint[0].x + offset,
				endpoint[0].y
			},
			(t_int_2d_point){
				endpoint[1].x,
				endpoint[1].y
			}
		},
		&g->screen_handle.frame_data,
		attack_next_px, &(t_nxt_px_f_arg){laser_color, NULL}
	);
}

void	render_attack(t_game *g, t_list *enemies)
{
	const t_int_2d_point	endpoint[2] = {
		(t_int_2d_point){
			g->screen_handle.width / 2.0f,
			g->screen_handle.height / 2.0f
		},
		(t_int_2d_point){
			g->screen_handle.width / 2.0f,
			g->screen_handle.height
		}
	};
	const t_color	laser_color = (t_color){222, 33, 65, 1};
	const size_t	base_width = (g->screen_handle.width * .5f) / 100;
	size_t			i;

	i = 0;
	while (i < 100)
	{
		draw_laser(
			endpoint, ((base_width / 50.0f) * i) - base_width, &laser_color, g
		);
		i += 1;
	}
	(void)enemies;
}

void	render_health_bar(t_game *g)
{
	const size_t		full = (g->screen_handle.width * 80.0f) / 100;
	const size_t		health = (full * g->player.hp) / 100.0f;
	const size_t		bar_height = 5;
	const size_t		horizontal_offset = (g->screen_handle.width * 10.0f) / 100;
	t_int_2d_point		px;

	px.y = 0;
	while (px.y < (int)bar_height)
	{
		px.x = 0;
		while (px.x < (int)health)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){px.x + horizontal_offset, px.y}
					),
				(t_color){255, 0, 0, 1}
			);
			px.x += 1;
		}
		px.y += 1;
	}
}

void	render_mana_bar(t_game *g)
{
	const size_t		full = (g->screen_handle.width * 50.0f) / 100.0f;
	const size_t		mana = (full * g->player.mana) / 100.0f;
	const size_t		bar_height = 5;
	const size_t		horizontal_offset = (g->screen_handle.width * 25.0f) / 100;
	const size_t		vertical_offset = 5 + 5;
	t_int_2d_point		px;

	px.y = 0;
	while (px.y < (int)bar_height)
	{
		px.x = 0;
		while (px.x < (int)mana)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){px.x + horizontal_offset, px.y + vertical_offset}
					),
				(t_color){0, 0, 255, 1}
			);
			px.x += 1;
		}
		px.y += 1;
	}
}

void	render_collision(t_game *g)
{
	// t_list			*cur;
	t_int_2d_point	px;

	// cur = ft_lstfind(g->enemies, enemy_collision, &g->player_pos);
	if (g->player.colliding)
	{
		// g->player_hp -= 1;
		px.y = 0;
		while (px.y < (int)g->screen_handle.height)
		{
			px.x = 0;
			while (px.x < (int)g->screen_handle.width)
			{
				if ((px.x + px.y) % 2)
					ft_put_px_to_image(
						&g->screen_handle.frame_data,
						ft_get_pixel_offset(&g->screen_handle.frame_data, px),
						(t_color){255, 0, 0, 1}
					);
				px.x += 1;
			}
			px.y += 1;
		}
	}
}

static t_data *get_wall_texture(t_game *game, const t_rc_ret_data *rc_ret_data)
{
	if (e_VERTICAL == rc_ret_data->side)
	{
		if (e_RAY_EAST == rc_ret_data->view_side_direction)
			return (&game->textures.wall.east);
		else
			return (&game->textures.wall.west);
	}
	else if (e_HORIZONTAL == rc_ret_data->side)
	{
		if (e_RAY_NORTH == rc_ret_data->view_forw_direction)
			return (&game->textures.wall.north);
		else
			return (&game->textures.wall.south);
	}
	else
		return (NULL);
}

t_column_info	get_column_info(
	size_t rendered_size,
	float gap,
	const t_raycast_return *rc_ret,
	t_game *g)
{
	float	scaling_factor;

	{
		if (0 == rendered_size)
			scaling_factor = INFINITY;
		else
			scaling_factor = (float)get_textures_size() / rendered_size;
	}
	return ((t_column_info){
		rendered_size,
		gap,
		NULL,//TODO			RIMUOVERE in t_column_info		!!!!!!!!!!!!!!!!!!!!!!!
		get_wall_texture(g, &rc_ret->wall),
		&g->\
		screen_handle.frame_data,
		get_texture_column(&rc_ret->wall),
		scaling_factor,
		e_true
		}
	);
}

static void	render_column(
	size_t column,
	t_game *g,
	const t_raycast_return *rc_ret
)
{
	const size_t			wall_size = roundf(
		g->screen_handle.height / rc_ret->wall.perp_dist
	);
	const float				gap = ( 
		((float)g->screen_handle.height - wall_size) / 2.0f
	);
	const t_column_info		col_info = get_column_info(
		wall_size, gap, rc_ret, g
		);
	t_int_2d_point			endpoint[2];
	
	endpoint[0] = (t_int_2d_point){column, gap};
	endpoint[1] = (t_int_2d_point){column, gap + (wall_size - 1)};
	if (0 == wall_size)
		return ;
	else
		bresenham_plot(
			endpoint,
			&g->screen_handle.frame_data,
			nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
		);
}

void	render_enemies(
	t_list *enemies,
	t_game *g
	)
{
	t_list	*cur;

	cur = enemies;
	while (cur)
	{
		render_enemy(cur->content, g);
		cur = cur->next;
	}
}

t_data	*get_enemy_texture(const t_enemy *enemy, t_game *g)
{
	if (enemy->health)
		return (&g->textures.enemy[0]);
	else //if (enemy->die_anim_frames)
	{
		// if (enemy->die_anim_frames % 2)
			return (&g->textures.enemy[1]);
		// return (NULL);
	}
	// else
	// 	return (NULL);
}

t_column_info	enemy_colinfo(
	size_t resized_texture_col,
	size_t enemy_size,
	const t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const float	gap = ( 
		((float)g->screen_handle.height - enemy_size) / 2.0f
	);
	float		scaling_factor;

	{
		if (0 == enemy_size)
			scaling_factor = INFINITY;
		else
			scaling_factor = (float)get_textures_size() / enemy_size;
	}
	return ((t_column_info){
		enemy_size,
		gap,
		NULL,
		get_enemy_texture(enemy_data->enemy, g),
		&g->\
		screen_handle.frame_data,
		resized_texture_col * scaling_factor,
		scaling_factor,
		e_false
		}
	);
}

void	enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const t_column_info		col_info = enemy_colinfo(
		resized_texture_col,
		enemy_data->enemy_size,
		enemy_data,
		g
	);
	t_int_2d_point	endpoint[2];
	
	endpoint[0] = (t_int_2d_point){
		screen_col,
		col_info.gap
		};
	endpoint[1] = (t_int_2d_point){
		screen_col,
		col_info.gap + (col_info.rendered_height - 1)
		};
	bresenham_plot(
		endpoint,
		&g->screen_handle.frame_data,
		nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
	);
}

void	render_enemy(
	t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const size_t	enemy_size = roundf(
		g->screen_handle.height / enemy_data->min_perp_dist
	);
	size_t			i;
	int				screen_col;

	if (
		0 == enemy_size
		|| e_false == enemy_data->enemy->alive
		|| (
			0 == enemy_data->enemy->health
			&& 0 == enemy_data->enemy->die_anim_frames % 2
			)
		)
		return ;
	// if (0 == enemy_data->enemy->health)
	// {
	// 	enemy_data->enemy->die_anim_frames -= 1;
	// 	if (0 == enemy_data->enemy->die_anim_frames % 2)
	// 	{
	// 		if (0 == enemy_data->enemy->die_anim_frames)
	// 			enemy_data->enemy->alive = e_false;
	// 		return ;
	// 	}
	// }
	enemy_data->enemy_size = enemy_size;
	screen_col = enemy_data->mid_screen_col;
	i = 0;
	while (i < enemy_size)
	{
		if (screen_col >= 0 && screen_col <= (int)g->screen_handle.width)
			enemy_render_col(screen_col, i, enemy_data, g);
		screen_col += 1;
		i += 1;
	}
}

int	get_texture_px(t_int_2d_point coordinate, const t_data *texture_data)
{
	const size_t	offset = ft_get_pixel_offset(texture_data, coordinate);
	const char		*byte_ptr = texture_data->addr + offset;
	int	px;

	// if (offset >= (size_t) 64 * texture_data->line_length || offset < 0)
	// {
	// 	px.rgb = 255 + (255 << 8) + (255 << 16);
	// 	printf(RED "out\n" RESET);
	// }
	// else
	// {
	// 	printf("\n");
	if (offset != (size_t)(-1)
		&& offset < (size_t)texture_data->height * texture_data->line_length
		)
		px = *(unsigned int *)byte_ptr;
	else
		return (-1);
	// }
	return (px);
}

// static int	rgb_clip(int val)
// {
// 	if (val < 0)
// 		return (0);
// 	else if (val > 255 + (255 << 8) + (255 << 16))
// 		return (255 + (255 << 8) + (255 << 16));
// 	else
// 		return (val);
// }

static int	nn_map_px_row(float y_mapping)
{
	if (y_mapping - floor(y_mapping) < 0.5f)
		return (texture_pt_clip(floor(y_mapping)));
	else
		return (texture_pt_clip(ceil(y_mapping)));
}

t_int_2d_point	nn_map_px(
	const t_column_info* col_info,
	const t_int_2d_point *cur_px
	)
{
	t_int_2d_point	original_texture_px;
	size_t		resized_texture_row;

	resized_texture_row = cur_px->y - col_info->gap;
	original_texture_px.x = col_info->texture_column;
	original_texture_px.y = nn_map_px_row(
		col_info->vertical_scaling_factor * resized_texture_row
		);
	return (original_texture_px);
}

int	nearest_neighbour(t_nxt_px_f_arg *nxt_px_f_arg)
{
	t_column_info	*col_info;
	t_int_2d_point	original_texture_px;

	col_info = (t_column_info *)nxt_px_f_arg->arg;
	original_texture_px = nn_map_px(col_info, nxt_px_f_arg->cur_px);
	if (
		original_texture_px.y == (int)get_textures_size() - 1
		&& col_info->draw_shadow
	)
		return (0);
	else
		return get_texture_px(
			original_texture_px,
			col_info->texture
		);
}

size_t	get_texture_column(const t_rc_ret_data *rc_ret_data)
{
	double			dist;
	const size_t	texture_size = get_textures_size();

	if (e_VERTICAL == rc_ret_data->side)
		dist = rc_ret_data->hit_point.y - rc_ret_data->square.y;
	else if (e_HORIZONTAL == rc_ret_data->side)
		dist = rc_ret_data->hit_point.x - rc_ret_data->square.x;
	else
		return (-1);
	return (texture_pt_clip(roundl(dist * (double)texture_size)));
}

static int	background_next_pixel(t_nxt_px_f_arg *nxt_px_f_arg)
{
	int	mlx_color;

	mlx_color = *((const int *)nxt_px_f_arg->arg);
	return (mlx_color);
}

static void	draw_background_bonus(t_game *g)
{
	t_int_2d_point	screen_px;

	screen_px.x = 0;
	while (screen_px.x < (int)g->screen_handle.frame_data.width)
	{
		screen_px.y = 0;
		while (screen_px.y < (int)g->screen_handle.frame_data.height)
		{
			ft_put_mlxpx_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(&g->screen_handle.frame_data, screen_px),
				get_texture_px(screen_px, &g->textures.background)
			);
			screen_px.y++;
		}
		screen_px.x++;
	}
}

//*		(FOV):(screen_width)	=	(west_ax_angle):(shift)
//*	
//*		shift = (west_ax_angle / FOV) * (screen_width)
int	west_axis_angle_to_px_shift(t_game *g)
{
	float	west_axis_angle;
	int		sign;

	if (g->player.west_angle < FOV)
	{
		west_axis_angle = g->player.west_angle;
		sign = -1;
	}
	else
	{
		west_axis_angle = 2 * M_PI - g->player.west_angle;
		sign = +1;
	}
	return (
		sign * roundf((west_axis_angle / FOV) * g->screen_handle.width)
	);
}

//*		rows / 2 = distance from west middle point (columns -1, rows / 2)
//*		when player is at position (x, 0)
//*
//*		This proportion gives the current wanted shift
//*		(
//*			WE WANT the sun to be shifted half the width of the screen
//*			when we look it from position (x, 0) with x any
//*		)
//*	
//*		(rows / 2):(screen_width / 2)	=	(dist):(shift)
//*	
//*		shift = dist * (screen_width / rows)
int	west_middle_point_dist_to_px_shift(t_game *g)
{
	const float	west_middle_pt_distance
		= g->map_handle.rows / 2.0f - g->player.pos.y;

	return (
		roundf(
			west_middle_pt_distance * (
				(float)g->screen_handle.width / g->map_handle.rows
				)
			)
		);
}

int	sun_set_offset(t_game *g)
{
	return (roundf(
		west_axis_angle_to_px_shift(g) + west_middle_point_dist_to_px_shift(g)
		)
	);
}

static size_t	sun_get_frame(void)
{
	static size_t	clock = 0;
	static size_t	frame = 0;
	const size_t	refresh_rate = 3;

	clock = (clock + 1) % refresh_rate;
	if (0 == clock)
		frame = (frame + 1) % SUN_FRAMES;
	return (frame);
}

static void	sun_draw_px(
	const t_int_2d_point *sun_frame_px, int col_offset,
	const t_data *sun_frame,
	t_game *g
	)
{
	t_int_2d_point	screen_mapped_px;
	int				mlx_px;

	screen_mapped_px.x = sun_frame_px->x + col_offset;
	screen_mapped_px.y = sun_frame_px->y;
	mlx_px = get_texture_px(
		(t_int_2d_point){sun_frame_px->x, sun_frame_px->y},
		sun_frame
		);
	if (
		0 <= screen_mapped_px.x
		&& screen_mapped_px.x < (int)g->screen_handle.width
		)
		ft_put_mlxpx_to_image(
			&g->screen_handle.frame_data,
			ft_get_pixel_offset(&g->screen_handle.frame_data, screen_mapped_px),
			mlx_px
		);
}

static void	draw_sun(t_game *g)
{
	t_int_2d_point	sun_frame_px;
	size_t			frame;
	int				col_offset;

	if (
		(g->player.west_angle >= FOV && g->player.west_angle <= 2 * M_PI - FOV)
	)
		return ;
	frame = sun_get_frame();
	col_offset = sun_set_offset(g);
	sun_frame_px.x = 0;
	while (sun_frame_px.x < (int)g->textures.sun[frame].width)
	{
		sun_frame_px.y = 0;
		while (sun_frame_px.y < (float)g->textures.sun[frame].height)
		{
			sun_draw_px(&sun_frame_px, col_offset, &g->textures.sun[frame], g);
			sun_frame_px.y++;
		}
		sun_frame_px.x++;
	}
}

static void			draw_background(t_game *g)
{
	const size_t	horizon = floor((float)g->screen_handle.height / 2);
	t_int_2d_point	vertices[2];
	t_nxt_px_f_arg	nxt_px_f_arg;
	const int		c_color = ft_get_mlx_color(g->map_handle.c_color);
	const int		f_color = ft_get_mlx_color(g->map_handle.f_color);

	{
		// print_color(g->map_handle.c_color, "ceiling");
		// print_color(g->map_handle.f_color, "floor");
		// printf("horizon is at:  %zu\n", horizon); 
	}
	// const
	vertices[0] = (t_int_2d_point){0, 0};
	vertices[1] = (t_int_2d_point){g->screen_handle.width - 1, 0};
	// color = ft_get_mlx_color(g->map_handle.c_color);
	while (vertices[0].y < (int)g->screen_handle.height)
	{
		if (vertices[0].y >= (int)horizon)
		{
			// color = ft_get_mlx_color(g->map_handle.f_color);
			nxt_px_f_arg.arg = &f_color;
			// printf(GREEN "HERE\n" RESET);
		}
		else
			nxt_px_f_arg.arg = &c_color;
		bresenham_plot(vertices,
			&g->screen_handle.frame_data, background_next_pixel, &nxt_px_f_arg);
		vertices[0].y += 1;
		vertices[1].y += 1;
	}
}

static t_2d_point	ray_dir_for_col(size_t col, t_game *g)
{
	t_2d_point	ray;
	const float	dilatation_factor =
		// = flt_round(
			((2.0f * col) / (g->screen_handle.width - 1.0f)) - 1.0f;//,
			// FLT_PRECISION
		// );
	// float		magnitude;

	ray.x = g->player.dir.x + dilatation_factor * g->player.camera_plane.x;
	ray.y = g->player.dir.y + dilatation_factor * g->player.camera_plane.y;

	//*		makign ray a magnitude 1 vector (versor)
	// magnitude = ft_vec_norm(ray);
	// ray.x = ray.x / magnitude;
	// ray.y = ray.y / magnitude;
	return (ray);
}

t_data	*get_door_texture(const t_spotted_door *door_data, t_game *g)
{
	if (door_front_side(door_data->door_ref->type, door_data->rc_data.side))
	{
		if (e_DOOR_CLOSED == door_data->door_ref->status)
			return (&g->textures.door.closed);
		if (e_DOOR_AJAR == door_data->door_ref->status)
			return (&g->textures.door.ajar);
		if (e_DOOR_OPEN == door_data->door_ref->status)
			return (&g->textures.door.open);
		return (NULL);
	}
	else
		return (get_wall_texture(g, &door_data->rc_data));
}

t_column_info	get_door_column_info(
	size_t rendered_size,
	float gap,
	const t_spotted_door *door_data,
	t_game *g)
{
	const t_data	*door_texture = get_door_texture(door_data, g);
	t_bool			draw_shadow;
	float			scaling_factor;

	if (door_texture == &g->textures.door.closed)
		draw_shadow = e_true;
	else
		draw_shadow = e_false;
	if (0 == rendered_size)
		scaling_factor = INFINITY;
	else
		scaling_factor = (float)get_textures_size() / rendered_size;
	return ((t_column_info){
		rendered_size,
		gap,
		NULL,//TODO			RIMUOVERE in t_column_info		!!!!!!!!!!!!!!!!!!!!!!!
		door_texture,
		&g->\
		screen_handle.frame_data,
		get_texture_column(&door_data->rc_data),
		scaling_factor,
		draw_shadow
		}
	);
}

void	render_door_col(
	const size_t screen_col,
	t_spotted_door *spotted_door,
	t_game *g
)
{
	const size_t			door_size = roundf(
		g->screen_handle.height / spotted_door->rc_data.perp_dist
	);
	const float				gap = ( 
		((float)g->screen_handle.height - door_size) / 2.0f
	);
	const t_column_info		col_info = get_door_column_info(
		door_size, gap, spotted_door, g
		);
	t_int_2d_point			endpoint[2];
	
	endpoint[0] = (t_int_2d_point){screen_col, gap};
	endpoint[1] = (t_int_2d_point){screen_col, gap + (door_size - 1)};
	if (0 == door_size)
		return ;
	else
		bresenham_plot(
			endpoint,
			&g->screen_handle.frame_data,
			nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
		);
}

void	render_doors(
	const size_t screen_col,
	const t_raycast_return *rc_ret,
	t_game *g
	)
{
	t_list	*cur;

	cur = rc_ret->doors;
	while (cur)
	{
		render_door_col(screen_col, cur->content, g);
		cur = cur->next;
	}
}