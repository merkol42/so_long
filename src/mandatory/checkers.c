/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:19:27 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:19:29 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	check_wall(char	**map)
{
	int	y;
	int	x;

	if (!map || !*map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (y == 0 && map[y][x] != '1')
				ft_error("Wall ERROR!");
			if (x == 0 && map[y][x] != '1')
				ft_error("Wall ERROR!");
			if (map[y][x + 1] == '\n' && map[y][x] != '1')
				ft_error("Wall ERROR!");
			if (map[y + 1] == NULL && map[y][x] != '1')
				ft_error("Wall ERROR!");
			x++;
		}
		y++;
	}
	return (1);
}

int	check_arg(char *file)
{
	int		i;
	int		j;
	char	*set;

	i = 2;
	j = 0;
	set = ".ber";
	while (file[i] != '.')
		i++;
	while (file[i] || set[j])
	{
		if (file[i] != set[j])
			ft_error("Uzantı Yanlış");
		j++;
		i++;
	}
	return (1);
}
