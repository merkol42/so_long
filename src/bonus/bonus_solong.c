/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 03:45:30 by merkol            #+#    #+#             */
/*   Updated: 2022/06/18 03:45:31 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

int	loop(t_game *g)
{
	update(g, get_object_count(g->map->map, 'G'));
	draw(g);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac == 2)
	{
		g.mlx = mlx_init();
		setup(&g, av[1], 1);
		g.win = mlx_new_window(g.mlx, g.map->widht * SIZE, \
			(g.map->height + 1) * SIZE, "PACMAN");
		mlx_hook(g.win, 17, 0, end_game, &g);
		mlx_loop_hook(g.mlx, loop, &g);
		mlx_key_hook(g.win, key_hook_bonus, &g);
		mlx_do_sync(g.mlx);
		mlx_loop(g.mlx);
	}
}
