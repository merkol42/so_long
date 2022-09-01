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

#include "long.h"

void	move_player(t_game *g)
{
	int	y;
	int	x;
	int	dirpoz;
	int	dirneg;

	x = g->player->x;
	y = g->player->y;
	dirpoz = (g->player->movedir - 2) * MOVESPEED;
	dirneg = (g->player->movedir + 2) * MOVESPEED;
	if (g->player->movedir > STOP && !collision(g, x, y + dirpoz, '1'))
		g->player->y += (g->player->movedir - 2) * MOVESPEED;
	else if (g->player->movedir < STOP && !collision(g, x + dirneg, y, '1'))
		g->player->x += (g->player->movedir + 2) * MOVESPEED;
	else
		g->player->movedir = STOP;
}

void	player_update(t_game *g)
{
	static int	counter;

	if (g->player->movedir == UP)
		g->player->current = g->player->up;
	if (g->player->movedir == DOWN)
		g->player->current = g->player->down;
	if (g->player->movedir == LEFT)
		g->player->current = g->player->left;
	if (g->player->movedir == RIGHT)
		g->player->current = g->player->right;
	if (g->player->movedir == STOP)
		g->player->current = g->player->pacmanfirst;
	if (counter++ == ASSETSPEED && g->player->current->next)
	{
		g->player->current = g->player->current->next;
		counter = 0;
	}
}

void	update(t_game *g)
{
	move_player(g);
	player_update(g);
	put_info(g, g->player->y, g->player->x);
}
