/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:29:00 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:29:01 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	get_player_pos(t_game *solong, int which)
{
	int		y;
	int		x;

	y = 0;
	while (y < solong->map->height)
	{
		x = 0;
		while (x < solong->map->widht)
		{
			if (solong->map->map[y][x] == which)
			{
				solong->player->x = x * 32;
				solong->player->y = y * 32;
			}
			x++;
		}
		y++;
	}
}

int	end_game(t_game *solong)
{
	int	y;
	int	x;

	y = solong->player->y / 32;
	x = solong->player->x / 32;
	if (solong->player->c_count != 0 || solong->map->map[y][x] != 'E')
		printf("\033[0;93mKAÇIŞ!\n");
	mlx_destroy_window(solong->mlx, solong->win);
	free(solong->map->map);
	free(solong->map);
	free(solong->assets);
	exit(EXIT_SUCCESS);
	return (1);
}

int	widht_counter(char *file)
{
	int		r;
	char	c;
	int		fd;
	int		x;

	x = 0;
	c = 0;
	fd = open(file, O_RDONLY);
	while (c != '\n')
	{
		r = read(fd, &c, 1);
		if (r == 0)
			break ;
		if (r < 0)
			return (0);
		if (c != '\n')
			x++;
	}
	return (x);
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	put_info(t_game *g, int y, int x)
{
	if (g->map->map[y / 32][x / 32] == 'C')
	{
		g->map->map[y / 32][x / 32] = '0';
		g->player->c_count--;
	}
	else if (g->player->c_count == 0 && g->map->map[y / 32][x / 32] == 'E')
	{
		printf("Tebrikler!!\n");
		end_game(g);
	}
	else if (g->player->movedir != 0)
	{
		g->movecount += MOVESPEED;
		if (g->movecount % 32 == 0)
		{
			printf("\033[0;93mHareket Sayısı: %d\n", g->movecount / 32);
		}
	}
}
