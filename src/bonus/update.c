/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@MOVESPEED2kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:28:50 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:28:52 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

void	next_dir(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x % 32;
	y = g->player->y % 32;
	if (g->player->movetemp > STOP && !x && \
	!checkcolission(g, g->player, g->player->movetemp, '1'))
		g->player->movedir = g->player->movetemp;
	else if (g->player->movetemp < STOP && !y \
	&& !checkcolission(g, g->player, g->player->movetemp, '1'))
		g->player->movedir = g->player->movetemp;
}

void	move_player(t_game *g)
{
	if (g->player->movedir > STOP && \
	!checkcolission(g, g->player, g->player->movedir, '1'))
	{
		g->player->y += (g->player->movedir - 2) * MOVESPEED;
		g->movecount += MOVESPEED;
	}
	else if (g->player->movedir < STOP && \
	!checkcolission(g, g->player, g->player->movedir, '1'))
	{
		g->player->x += (g->player->movedir + 2) * MOVESPEED;
		g->movecount += MOVESPEED;
	}
	else
		g->player->movedir = STOP;
}

void	asset_update(t_game *g)
{
	static int	counter;

	if (g->player->movedir == UP)
		g->player->current = g->player->up;
	else if (g->player->movedir == DOWN)
		g->player->current = g->player->down;
	else if (g->player->movedir == LEFT)
		g->player->current = g->player->left;
	else if (g->player->movedir == RIGHT)
		g->player->current = g->player->right;
	else if (g->player->movedir == STOP)
		g->player->current = g->player->pacmanfirst;
	if (counter++ > ASSETSPEED && g->player->movedir != STOP)
	{
		g->player->current = g->player->current->next;
		counter = 0;
	}
}

void	update(t_game *g, int bonus)
{
	(void)bonus;
	next_dir(g);
	move_player(g);
	asset_update(g);
	if (bonus != 0 && g->enemy)
	{
		move_enemy(g);
		enemy_update(g);
	}
	put_info(g, g->player->y, g->player->x);
}
