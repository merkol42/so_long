/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ghost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:10:44 by merkol            #+#    #+#             */
/*   Updated: 2022/06/21 11:10:45 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

void	enemy_update(t_game *g)
{
	static int	counter;

	if (g->enemy->movedir == LEFT)
		g->enemy->current = g->enemy->left;
	else if (g->enemy->movedir == RIGHT)
		g->enemy->current = g->enemy->right;
	else if (g->enemy->movedir == UP)
		g->enemy->current = g->enemy->up;
	else if (g->enemy->movedir == DOWN)
		g->enemy->current = g->enemy->down;
	if (counter++ > ASSETSPEED)
	{
		g->enemy->current = g->enemy->current->next;
		counter = 0;
	}
}

int	get_next_dir(int dir)
{
	static int	random;

	if (random++ > 4)
		random = 0;
	if (random == 0 && dir)
		return (LEFT);
	else if (random == 1)
		return (RIGHT);
	else if (random == 2)
		return (DOWN);
	else if (random == 3)
		return (UP);
	else
		return (LEFT);
}

void	move_enemy(t_game *g)
{
	if (g->enemy->movedir > STOP && \
		!checkcolission(g, g->enemy, g->enemy->movedir, '1'))
		g->enemy->y += (g->enemy->movedir - 2) * MOVESPEED / 2;
	else if (g->enemy->movedir < STOP && \
		!checkcolission(g, g->enemy, g->enemy->movedir, '1'))
		g->enemy->x += (g->enemy->movedir + 2) * MOVESPEED / 2;
	else
		g->enemy->movedir = get_next_dir(g->enemy->movedir);
}
