/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:28:00 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:28:01 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

t_list	*ft_animup(t_game *g, int i)
{
	t_list	*anim;
	t_list	*tail;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_up.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_open_up.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_up.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_closed.xpm", &i, &i)));
	tail = ft_lstlast(anim);
	tail->next = anim;
	return (anim);
}

t_list	*ft_animdown(t_game *g, int i)
{
	t_list	*anim;
	t_list	*tail;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_down.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_open_down.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_down.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_closed.xpm", &i, &i)));
	tail = ft_lstlast(anim);
	tail->next = anim;
	return (anim);
}

t_list	*ft_animleft(t_game *g, int i)
{
	t_list	*anim;
	t_list	*tail;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_left.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_open_left.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_left.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_closed.xpm", &i, &i)));
	tail = ft_lstlast(anim);
	tail->next = anim;
	return (anim);
}

t_list	*ft_animright(t_game *g, int i)
{
	t_list	*anim;
	t_list	*tail;

	anim = NULL;
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_right.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_open_right.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_semi_right.xpm", &i, &i)));
	ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(g->mlx, \
		"./sprites/Pac-Man/pac_closed.xpm", &i, &i)));
	tail = ft_lstlast(anim);
	tail->next = anim;
	return (anim);
}
