/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:46:34 by merkol            #+#    #+#             */
/*   Updated: 2022/06/21 15:46:35 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	key_hook(int keycode, t_game *g)
{
	if (keycode == ESC)
		end_game(g);
	if (keycode == W)
		g->player->movedir = UP;
	if (keycode == A)
		g->player->movedir = LEFT;
	if (keycode == S)
		g->player->movedir = DOWN;
	if (keycode == D)
		g->player->movedir = RIGHT;
	return (1);
}
