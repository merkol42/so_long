/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ghost_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:11:16 by merkol            #+#    #+#             */
/*   Updated: 2022/06/21 11:11:20 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

t_list	*ghost_up(t_game *g, int size)
{
	t_list	*anim;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_up1.xpm", &size, &size)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_up2.xpm", &size, &size)));
	anim->next->next = anim;
	return (anim);
}

t_list	*ghost_down(t_game *g, int size)
{
	t_list	*anim;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_down1.xpm", &size, &size)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_down2.xpm", &size, &size)));
	anim->next->next = anim;
	return (anim);
}

t_list	*ghost_left(t_game *g, int size)
{
	t_list	*anim;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_left1.xpm", &size, &size)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_left2.xpm", &size, &size)));
	anim->next->next = anim;
	return (anim);
}

t_list	*ghost_right(t_game *g, int size)
{
	t_list	*anim;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_right1.xpm", &size, &size)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"sprites/Ghosts/B/ghost_right2.xpm", &size, &size)));
	anim->next->next = anim;
	return (anim);
}
