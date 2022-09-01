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

#include "long.h"

void	set_collect(t_game *solong, char which)
{
	int		y;
	int		x;
	int		counter;

	y = -1;
	counter = 0;
	while (++y < solong->map->height)
	{
		x = -1;
		while (++x < solong->map->widht)
		{
			if (which == 'C' && solong->map->map[y][x] == which)
			{
				solong->player->c_count++;
				counter++;
			}
			else if (which == 'E' && solong->map->map[y][x] == which)
				counter++;
			else if (which == 'P' && solong->map->map[y][x] == which)
				counter++;
		}
	}
	if (counter == 0)
		ft_error("En Az Bir 'E,C' ve bir 'P'");
}

int	get_block(t_game *solong, int x, int y, char arg)
{
	t_map	*map;

	map = solong->map;
	while ((x / 32) <= solong->map->widht)
	{
		if (map->map[y / 32][x / 32] == arg)
			return (x / 32);
		x++;
	}
	return (0);
}

int	collision(t_game *solong, int x, int y, char arg)
{
	t_map	*map;
	float	wall;
	float	wall2;
	int		tempy;

	map = solong->map;
	tempy = y;
	while (tempy % 32 != 0)
		tempy++;
	if (y > (map->height - 1) * 32)
		return (0);
	wall = get_block(solong, x, y, arg) - (x / (float)(32));
	wall2 = get_block(solong, x, tempy, arg) - (x / (float)32);
	if (wall < 1 || wall2 < 1)
		return (1);
	return (0);
}
