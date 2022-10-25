/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:07:21 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/27 12:33:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_next_line_rec(int fd, t_fd_buffer *buf_handle);
static t_bool	gnl_read_file_in_buf(t_fd_buffer *buf_handle, int fd);
static t_bool	gnl_get_line_from_buffer(t_fd_buffer *buf_handle, char **str);
static size_t	gnl_scan_next_line_in_buf(t_fd_buffer *buf_handle,
					t_bool *nl_found);
//* end of static declarations

char	*get_next_line(int fd)
{
	static t_fd_buffer	buf_handle = (t_fd_buffer){NULL, BUFFER_SIZE, 0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf_handle.offset == 0)
		buf_handle.buffer_size = BUFFER_SIZE;
	return (get_next_line_rec(fd, &buf_handle));
}

static char	*get_next_line_rec(int fd, t_fd_buffer *buf_handle)
{
	char		*str;
	t_bool		nl_found;

	if (buf_handle->offset == 0)
	{
		if (e_false == gnl_read_file_in_buf(buf_handle, fd))
			return (NULL);
	}
	nl_found = gnl_get_line_from_buffer(buf_handle, &str);
	if (buf_handle->offset == 0 || buf_handle->buf[buf_handle->offset] == '\0')
	{
		free(buf_handle->buf);
		if (buf_handle->offset == 0 && !nl_found)
		{
			buf_handle->buffer_size = buf_handle->buffer_size + 5;
			return (ft_strjoin(str, get_next_line_rec(fd, buf_handle),
						e_true, e_true));
		}
		buf_handle->offset = 0;
	}
	return (str);
}

/**
 * @brief this function reads buf_handle->buffer_size characters from fd
 * and puts them inside buf_handle->buf 
 * 
 * @param buf_handle pointer to a t_fd_buffer structure
 * @param fd file descriptor
 * @return t_bool true iff the read function doesn't fail
 */
static t_bool	gnl_read_file_in_buf(t_fd_buffer *buf_handle, int fd)
{
	buf_handle->buf = (char *) malloc((buf_handle->buffer_size + 1) * sizeof(char));
	ft_memset(buf_handle->buf, '\0', buf_handle->buffer_size + 1);
	if (read(fd, buf_handle->buf, buf_handle->buffer_size) <= 0)
	{
		free(buf_handle->buf);
		return (e_false);
	}
	return (e_true);
}

/**
 * @brief this function takes the next line from buffer
 * accessed through the [buf_handle] structure pointer;
 * if no line is found, the whole buffer is read
 * 
 * @param buf_handle pointer to a t_fd_buffer structure
 * @param str the address of the char * variable where to store
 * the content read
 * @return t_bool true iff a new line is found
 */
static t_bool	gnl_get_line_from_buffer(t_fd_buffer *buf_handle, char **str)
{
	t_bool	nl_found;
	size_t	line_len;
	size_t	buffer_start;
	size_t	i;

	i = gnl_scan_next_line_in_buf(buf_handle, &nl_found);
	//* setting_next_line_len
	{
		if (buf_handle->buf[i] == '\0')
			line_len = i - buf_handle->offset;
		else
			line_len = i - buf_handle->offset + 1;
	}
	//* updating_buffer_offset
	{
		buffer_start = buf_handle->offset;
		if (i == buf_handle->buffer_size - 1
			|| buf_handle->buf[i] == '\0')
			buf_handle->offset = 0;
		else
			buf_handle->offset = i + 1;
	}
	ft_strlcpy(str, buf_handle->buf + buffer_start, line_len);
	return (nl_found);
}

/**
 * @brief this functions looks for the next line
 * inside the buffer accessed through the [buf_handle] structure pointer
 * 
 * @param buf_handle pointer to a t_fd_buffer structure
 * @param nl_found if a new line is found, it is set to e_true,
 * otherwise it is set to e_false.
 * @return size_t the new index after the end of the next line found,
 * or the index of the first '\0' if no line is found
 */
static size_t	gnl_scan_next_line_in_buf(t_fd_buffer *buf_handle,
					t_bool *nl_found)
{
	size_t	i;

	*nl_found = e_false;
	i = buf_handle->offset;
	while (i < buf_handle->buffer_size)
	{
		if (buf_handle->buf[i] == '\n'
			|| buf_handle->buf[i] == '\0')
		{
			if (buf_handle->buf[i] == '\n')
				*nl_found = e_true;
			break ;
		}
		i++;
	}
	return (i);
}
