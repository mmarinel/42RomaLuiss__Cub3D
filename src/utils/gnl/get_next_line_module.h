/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_module.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:17:13 by earendil          #+#    #+#             */
/*   Updated: 2022/12/08 19:59:09 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_MODULE_H
# define GET_NEXT_LINE_MODULE_H

//* main exposed function

char	*get_next_line(int fd);
char	*get_next_line_nonl(int fd);

#endif