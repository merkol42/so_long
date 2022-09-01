/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:10:16 by merkol            #+#    #+#             */
/*   Updated: 2022/06/21 11:10:17 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

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

int	key_hook_bonus(int keycode, t_game *g)
{
	if (keycode == ESC)
		end_game(g);
	if (keycode == W)
		g->player->movetemp = UP;
	if (keycode == A)
		g->player->movetemp = LEFT;
	if (keycode == S)
		g->player->movetemp = DOWN;
	if (keycode == D)
		g->player->movetemp = RIGHT;
	return (1);
}
