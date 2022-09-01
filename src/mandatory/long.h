/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:46:45 by merkol            #+#    #+#             */
/*   Updated: 2022/06/21 15:46:46 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include "../../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../../includes/structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_read(int fd, char *mystr);
char	*ft_line(char *mystr);
char	*ft_newstr(char *mystr);
// utils
int		end_game(t_game *solong);
void	ft_error(char *str);
void	get_player_pos(t_game *solong, int which);
void	put_info(t_game *g, int y, int x);
void	set_collect(t_game *solong, char which);
//map_read
char	**map_read(char *file);
char	**map_alloc(char *file);
int		line_counter(char *file);
//fill process
void	fill_solong(t_game *solong, char *file);
int		widht_counter(char *file);
void	fill_assets(t_game *solong);
//checkers
int		check_wall(char	**map);
int		check_arg(char *file);
//fill_animation
t_list	*ft_animup(t_game *g, int i);
t_list	*ft_animdown(t_game *g, int i);
t_list	*ft_animleft(t_game *g, int i);
t_list	*ft_animright(t_game *g, int i);
//draw
void	draw(t_game *g);
void	draw_map(t_game *g);
//update
int		collision(t_game *solong, int x, int y, char arg);
int		get_block(t_game *solong, int x, int y, char arg);
void	move_player(t_game *g);
void	player_update(t_game *g);
void	update(t_game *g);
//key process
int		key_hook_bonus(int keycode, t_game *g);
int		key_hook(int keycode, t_game *g);
#endif
