/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:16:43 by earendil          #+#    #+#             */
/*   Updated: 2022/11/03 18:19:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static void		map_size( const char* map_string,
					size_t* rows, size_t* columns );
static char			**complete_map( const char* normalized_map_string,
						t_map_holder *map_handle );
static char			*complete_map_row( char *split_row, size_t missing );
static char			*ft_normalized_map_row( const char* row );
//* end of static declarations

//* I Know this is (perhaps) bad !!!!
char	**read_map( int map_fd, t_map_holder* map_handle )
{
	char	**map;
	char	*map_string;
	char	*line;

	map_string = NULL;
	while (e_true)
	{
		line = get_next_line(map_fd);
		if (NULL == line)
			break ;
		map_string = ft_strjoin(
			map_string,
			ft_normalized_map_row(line),
			e_true, e_true
		);
		free(line);
	}
	printf("\nmap_string is: %s\n\n", map_string);
	map_size(map_string, &map_handle->rows, &map_handle->columns);
	map = complete_map(map_string, map_handle);
	if (NULL != map_string)
		free(map_string);
	return (map);
}

static void	map_size( const char* map_string,
					size_t* rows, size_t* columns )
{
	int		max_row_len;
	int		cur_row_len;
	char	**splitted;
	size_t	cursor;

	max_row_len = 0;
	cursor = 0;
	splitted = ft_split(map_string, '\n');
	if (NULL != splitted)
	{
		while (splitted[cursor])
		{
			if (e_false == ft_str_isempty(splitted[cursor]))
			{
				cur_row_len = ft_strlen(splitted[cursor]);
				if (cur_row_len > max_row_len)
					max_row_len = cur_row_len;
			}
			cursor += 1;
		}
	}
	ft_splitclear(splitted);
	*columns = max_row_len;
	*rows = cursor;
}

static char	**complete_map( const char* normalized_map_string,
				t_map_holder *map_handle )
{
	char	**splitted;
	size_t	cursor;

	splitted = ft_split(normalized_map_string, '\n');
	if (NULL == splitted)
		return (NULL);
	cursor = 0;
	while (splitted[cursor])
	{
		splitted[cursor] = complete_map_row(
			splitted[cursor],
			map_handle->columns - ft_strlen(splitted[cursor])
		);
		cursor += 1;
	}
	return (splitted);
}

static char	*complete_map_row( char *split_row, size_t missing )
{
	return (
		ft_strjoin(
			split_row,
			ft_string_new(' ', missing),
			e_true, e_true
		)
	);
}

/**
 * @brief this functions returns a normalized map row.
 * Normalized map rows always begin with at least 1 space character,
 * so that we can still detect empty lines
 * when splitting the map on the [\n] character
 * 
 * @param row 
 * @return char* 
 */
static char	*ft_normalized_map_row( const char* row )
{
	return (
		ft_strjoin(" ", (char *)row, e_false, e_false)
	);
}
