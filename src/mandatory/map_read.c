/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:28:31 by merkol            #+#    #+#             */
/*   Updated: 2022/06/15 13:28:32 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	line_counter(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

char	**map_alloc(char *file)
{
	char	**map;
	int		line_count;

	line_count = line_counter(file);
	if (line_count <= 0)
		ft_error("Dosya Açma Hatası");
	map = (char **)malloc(sizeof(char *) * line_count + 1);
	if (!map)
		ft_error("Malloc Hatası");
	return (map);
}

char	**map_read(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = map_alloc(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < line_counter(file))
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
