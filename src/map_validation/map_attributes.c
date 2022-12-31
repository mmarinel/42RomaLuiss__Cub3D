/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:08:21 by earendil          #+#    #+#             */
/*   Updated: 2022/12/31 18:17:13 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static void		parse_fields_line( t_map_holder *map_handle, const char *line,
					t_bool *err_flag);
static void		parse_wall_texture( t_map_holder *map_handle,
					const char *id, const char *path );
static void		parse_rgb_field( t_map_holder *map_handle,
					const char *id, char *rgb_string,
					t_bool *err_flag );
static void		parse_rgb_item( int *item_ref, const char *channel,
					t_bool *err_flag );
//* end of static declarations

t_bool	is_map_attributes_ok( int map_fd, t_map_holder *map_handle )
{
	t_bool	error_found;
	char	*next_line;

	error_found = e_false;
	while (
		e_false == map_fields_complete(map_handle)
		&& e_false == error_found
	)
	{
		next_line = get_next_line_nonl(map_fd);
		if (NULL == next_line)
			error_found = e_true;
		else
		{
			if (e_false == ft_str_isempty(next_line))
				parse_fields_line(map_handle, next_line, &error_found);
			free(next_line);
		}
	}
	return (error_found == e_false);
}

static void	parse_fields_line( t_map_holder *map_handle, const char *line,
					t_bool *err_flag)
{
	char	**splitted;
	char	*right_hand_side;

	splitted = ft_multisplit(line, " VV\t");
	if (ft_splitlen(splitted) < 2)
		*err_flag = e_true;
	else
	{
		right_hand_side = ft_split_merge(splitted + 1, " ", e_false);
		if (is_attrs_player_dir_char(splitted[0]))
			parse_wall_texture(map_handle, splitted[0], splitted[1]);
		else if (is_attrs_color_field_char(splitted[0]))
			parse_rgb_field(map_handle, splitted[0], right_hand_side,
				err_flag);
		else
			*err_flag = e_true;
		free(right_hand_side);
	}
	ft_splitclear(&splitted);
}

static void	parse_wall_texture( t_map_holder *map_handle,
				const char *id, const char *path )
{
	if (0 == ft_strcmp(id, "NO"))
		read_texture_attr(&map_handle->no_texture, path);
	else if (0 == ft_strcmp(id, "SO"))
		read_texture_attr(&map_handle->so_texture, path);
	else if (0 == ft_strcmp(id, "WE"))
		read_texture_attr(&map_handle->we_texture, path);
	else if (0 == ft_strcmp(id, "EA"))
		read_texture_attr(&map_handle->ea_texture, path);
}

static void	parse_rgb_field( t_map_holder *map_handle,
				const char *id, char *rgb_string,
				t_bool *err_flag )
{
	char	**splitted;
	t_color	*color_field;

	if (is_floor_color_id(id))
		color_field = &map_handle->f_color;
	else
		color_field = &map_handle->c_color;
	splitted = ft_split(rgb_string, ',');
	if (ft_splitlen(splitted) != 3)
		*err_flag = e_true;
	else
	{
		parse_rgb_item(&color_field->red, splitted[0], err_flag);
		parse_rgb_item(&color_field->green, splitted[1], err_flag);
		parse_rgb_item(&color_field->blue, splitted[2], err_flag);
		if (ft_iscolor(color_field->red, color_field->green, color_field->blue)
			&& e_false == *err_flag
		)
			color_field->alpha = 1;
		else
			*err_flag = e_true;
	}
	ft_splitclear(&splitted);
}

static void	parse_rgb_item( int *item_ref, const char *channel,
				t_bool *err_flag )
{
	if (ft_isdigit_string(channel))
	{
		*item_ref = ft_atoi(channel);
		// printf(YELLOW"rgb component is %d\n"RESET, *item_ref);
	}
	else
	{
		*item_ref = -1;
		*err_flag = e_true;
	}
}
