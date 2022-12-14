/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 19:57:16 by earendil         ###   ########.fr       */
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
//*		end of static declarations

// int	ln_clipper(t_clip_opcode opcode, size_t size);
// size_t	ln_clip(size_t coordinate);
size_t	get_texture_column(const t_raycast_return *rc_ret, const t_game *game);
int	linear_interpolation(t_nxt_px_f_arg *nxt_px_f_arg);
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
		if (rc_return.spotted_enemy)
			update_enemy_list(&enemies, &rc_return, col);
		render_column(col, g, &rc_return);
		col++;
	}
	render_enemies(enemies, g);
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		g->screen_handle.frame_data.img,
		0, 0);
}

static t_data *get_wall_texture(t_game *game, const t_raycast_return *rc_ret)
{
	if (e_VERTICAL == rc_ret->side)
	{
		if (e_RAY_EAST == rc_ret->view_side_direction)
			return (&game->wall_texture.east);
		else
			return (&game->wall_texture.west);
	}
	else if (e_HORIZONTAL == rc_ret->side)
	{
		if (e_RAY_NORTH == rc_ret->view_forw_direction)
			return (&game->wall_texture.north);
		else
			return (&game->wall_texture.south);
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
		rc_ret,
		get_wall_texture(g, rc_ret),
		&g->\
		screen_handle.frame_data,
		get_texture_column(rc_ret, g),
		scaling_factor,
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
		g->screen_handle.height / rc_ret->perp_dist
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
			linear_interpolation, &(t_nxt_px_f_arg){&col_info, NULL}
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
	if (enemy->alive)
		return (&g->enemy_texture[0]);
	else
		return (&g->enemy_texture[1]);
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
		col_info.gap + (col_info.wall_size - 1)
		};
	bresenham_plot(
		endpoint,
		&g->screen_handle.frame_data,
		linear_interpolation, &(t_nxt_px_f_arg){&col_info, NULL}
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
	size_t	i;
	int		screen_col;

	if (0 == enemy_size)
		return ;
	enemy_data->enemy_size = enemy_size;
	screen_col = enemy_data->mid_screen_col - enemy_size;
	i = 0;
	while (i < enemy_size)
	{
		if (screen_col >= 0)
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
		px = *(unsigned int *)byte_ptr;
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

int	linear_interpolation(t_nxt_px_f_arg *nxt_px_f_arg)
{
	t_column_info	*col_info;
	size_t			resized_row;
	t_2d_point		mapped;

	col_info = (t_column_info *)nxt_px_f_arg->arg;
	resized_row = nxt_px_f_arg->cur_px->y - col_info->gap;
	mapped.x = col_info->texture_column;
	mapped.y = col_info->scaling_factor * resized_row;
	// ft_print_2d_point("mapped", mapped);
	if (resized_row == col_info->wall_size - 1)
		return (0);
	if (mapped.y - floor(mapped.y) < 0.5f)//ceil(mapped.y) - mapped.y)
	{
		// printf(BOLDCYAN "QUI!\n" RESET);
		return get_texture_px(
			(t_int_2d_point){mapped.x, texture_pt_clip(floor(mapped.y))},//, col_info->rc_ret->side
			col_info->texture
		);
	}
	else {
		// printf(BOLDCYAN "QUAA!\n" RESET);
		return get_texture_px(
			(t_int_2d_point){mapped.x, texture_pt_clip(ceil(mapped.y))},
			col_info->texture
		);
	}
}
	// return rgb_clip(floor(
	// 	(
	// 		(1.0f - (mapped.y - ln_clip(floor(mapped.y)))) * get_texture_px(
	// 			(t_int_2d_point){mapped.x, ln_clip(floor(mapped.y))},
	// 			col_info->texture
	// 			)
	// 	)
	// 	+ (
	// 		(1.0f - (ln_clip(ceil(mapped.y)) - mapped.y)) * get_texture_px(
	// 			(t_int_2d_point){mapped.x, ln_clip(ceil(mapped.y))},
	// 			col_info->texture
	// 		)
	// 	)
	// ));

size_t	get_texture_column(const t_raycast_return *rc_ret, const t_game *game)
{
	float			dist;
	size_t			col;
	const size_t	texture_size = game->wall_texture.north.width;

	if (e_VERTICAL == rc_ret->side)
		dist = rc_ret->hit_point.y - floor(rc_ret->hit_point.y);
	else if (e_HORIZONTAL == rc_ret->side)
		dist = rc_ret->hit_point.x - floor(rc_ret->hit_point.x);
	else
		return (-1);
	col = 0;
	while (col < texture_size)
	{
		if (
			(float)col / texture_size <= dist
			&& dist <= (float)(col + 1) / texture_size
		)
			break ;
		col += 1;
	}
	return (col);
}

// static void	print_color(t_color color, const char *msg)
// {
// 	// printf(YELLOW "%s: (R=%d G=%d B=%d)\n" RESET, msg, color.red, color.green, color.blue);
// }

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
				get_texture_px(screen_px, &g->background)
			);
			screen_px.y++;
		}
		screen_px.x++;
	}
}

static void	draw_sun(t_game *g)
{
	t_int_2d_point	screen_px;
	int				mlx_px;

	screen_px.x = 0;
	while (screen_px.x < (int)g->screen_handle.frame_data.width)
	{
		screen_px.y = 0;
		while (screen_px.y < (float)g->screen_handle.frame_data.height / 2)
		{
			mlx_px = get_texture_px(screen_px, &g->sun[0]);
			// if (screen_px.x == 0 && screen_px.y == 0)
			// 	printf(YELLOW"cur_px: %d\n" RESET, mlx_px);
			if (mlx_px > 0)
				ft_put_mlxpx_to_image(
					&g->screen_handle.frame_data,
					ft_get_pixel_offset(&g->screen_handle.frame_data, screen_px),
					mlx_px
				);
			screen_px.y++;
		}
		screen_px.x++;
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
	const float	dilatation_factor
		= flt_round(
			((2.0f * col) / (g->screen_handle.width - 1.0f)) - 1.0f,
			FLT_PRECISION
		);
	// float		magnitude;

	ray.x = g->player_dir.x + dilatation_factor * g->camera_plane.x;
	ray.y = g->player_dir.y + dilatation_factor * g->camera_plane.y;

	//*		makign ray a magnitude 1 vector (versor)
	// magnitude = ft_vec_norm(ray);
	// ray.x = ray.x / magnitude;
	// ray.y = ray.y / magnitude;
	return (ray);
}
