/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:11:55 by earendil          #+#    #+#             */
/*   Updated: 2022/12/31 18:16:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	read_texture_attr(char **ref, const char *path)
{
	if (NULL == ref)
		return ;
	ft_free(*ref);
	*ref = ft_strdup(path);
}
