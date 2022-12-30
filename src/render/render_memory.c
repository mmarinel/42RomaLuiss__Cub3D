/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:17:31 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 22:02:11 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	clean_rays(t_list **rays)
{
	ft_lstclear(rays, free);
}

void	clean_entities(t_list **entities)
{
	ft_lstclear(entities, free);
}
