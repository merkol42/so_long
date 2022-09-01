/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 03:45:02 by merkol            #+#    #+#             */
/*   Updated: 2022/06/18 03:45:03 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

void	fill_static_assets(t_game *g)
{
	g->assets->wall = mlx_xpm_file_to_image(g->mlx, \
		WALL, &g->assets->size, &g->assets->size);
	g->assets->collect = mlx_xpm_file_to_image(g->mlx, \
		COLLECT, &g->assets->size, &g->assets->size);
	g->assets->exit = mlx_xpm_file_to_image(g->mlx, \
		EXIT, &g->assets->size, &g->assets->size);
}

void	fill_player(t_game *g, int i)
{
	get_character_pos(g, 'P');
	g->player->movedir = STOP;
	g->player->movetemp = STOP;
	g->player->up = ft_animup(g, 32);
	g->player->down = ft_animdown(g, 32);
	g->player->left = ft_animleft(g, 32);
	g->player->right = ft_animright(g, 32);
	g->player->pacmanfirst = (t_list *)malloc(sizeof(t_list));
	g->player->pacmanfirst->content = mlx_xpm_file_to_image(g->mlx, \
		"sprites/Pac-Man/pac_open_closed.xpm", &i, &i);
	g->player->pacmanfirst->next = NULL;
	g->player->current = g->player->pacmanfirst;
	g->player->next = NULL;
}

void	setup_enemy(t_game *g, int size)
{
	g->enemy = (t_player *)malloc(sizeof(t_player));
	get_enemy_pos(g->enemy, g->map->map);
	g->enemy->up = ghost_up(g, size);
	g->enemy->down = ghost_down(g, size);
	g->enemy->left = ghost_left(g, size);
	g->enemy->right = ghost_right(g, size);
	g->enemy->movedir = RIGHT;
	g->enemy->current = g->enemy->right;
	g->enemy->next = NULL;
}

void	setup(t_game *g, char *file, int bonus)
{
	check_arg(file);
	g->map = (t_map *)malloc(sizeof(t_map));
	g->map->map = map_read(file);
	check_wall(g->map->map);
	g->player = (t_player *)malloc(sizeof(t_player));
	g->assets = (t_assets *)malloc(sizeof(t_assets));
	g->enemy = NULL;
	fill_static_assets(g);
	g->map->height = line_counter(file);
	g->map->widht = widht_counter(file);
	g->assets->size = 32;
	g->movecount = 0;
	g->player->c_count = 0;
	set_collect(g, 'C');
	set_collect(g, 'E');
	set_collect(g, 'P');
	fill_player(g, 32);
	if (bonus == 1 && get_object_count(g->map->map, 'G'))
		setup_enemy(g, 32);
}
