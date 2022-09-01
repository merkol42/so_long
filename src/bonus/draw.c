/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:27:42 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:27:43 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

void	draw_map(t_game *g)
{
	int		y;
	int		x;

	y = 0;
	while (y < g->map->height)
	{
		x = 0;
		while (x < g->map->widht)
		{
			if (g->map->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, \
				g->assets->wall, x * SIZE, y * SIZE);
			else if (g->map->map[y][x] == 'E' && g->player->c_count == 0)
				mlx_put_image_to_window(g->mlx, g->win, \
				g->assets->exit, x * SIZE, y * SIZE);
			else if (g->map->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, \
				g->assets->collect, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	draw_enemy(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->enemy->current->content, \
		g->enemy->x, g->enemy->y);
}

void	draw(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	draw_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->player->current->content, \
		g->player->x, g->player->y);
	if (g->enemy)
		draw_enemy(g);
	put_string(g, ft_itoa(g->movecount / 32));
	mlx_do_sync(g->mlx);
}
