/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 03:45:47 by merkol            #+#    #+#             */
/*   Updated: 2022/06/18 03:45:48 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/long.h"

int	get_object_count(char **map, int which)
{
	int	x;
	int	y;
	int	counter;

	counter = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == which)
				counter++;
		}
	}
	return (counter);
}

void	set_collect(t_game *g, char which)
{
	int		y;
	int		x;
	int		counter;

	y = -1;
	counter = 0;
	while (++y < g->map->height)
	{
		x = -1;
		while (++x < g->map->widht)
		{
			if (which == 'C' && g->map->map[y][x] == which)
			{
				g->player->c_count++;
				counter++;
			}
			else if (which == 'E' && g->map->map[y][x] == which)
				counter++;
			else if (which == 'P' && g->map->map[y][x] == which)
				counter++;
		}
	}
	if (counter == 0)
		ft_error("En Az Bir 'E,C' ve bir 'P'");
}

void	get_enemy_pos(t_player *ghost, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'G')
			{
				ghost->x = x * 32;
				ghost->y = y * 32;
				return ;
			}
		}
	}
}

int	put_string(t_game *g, char *string)
{
	int		x;
	int		y;
	char	*str;

	x = g->map->widht * 32;
	y = (g->map->height + 1) * 32;
	str = ft_strjoin("Hareket sayısı :", string);
	mlx_string_put(g->mlx, g->win, (x / 2) - 70, y, 0x00FFFF00, str);
	return (1);
}

int	checkcolission(t_game *g, t_player *character, int direction, char c)
{
	int		x;
	int		y;
	int		modx;
	int		mody;
	char	**map;

	x = character->x / SIZE;
	y = character->y / SIZE;
	modx = (character->x % SIZE);
	mody = (character->y % SIZE);
	map = g->map->map;
	if (direction == LEFT && (!modx
			&& ((mody && map[y + 1][x - 1] == c) || map[y][x - 1] == c)))
		return (1);
	if (direction == RIGHT && (!modx
			&& ((mody && map[y + 1][x + 1] == c) || map[y][x + 1] == c)))
		return (1);
	if (direction == UP && (!mody
			&& ((modx && map[y - 1][x + 1] == c) || map[y - 1][x] == c)))
		return (1);
	if (direction == DOWN && (!mody
			&& ((modx && map[y + 1][x + 1] == c) || map[y + 1][x] == c)))
		return (1);
	return (0);
}
