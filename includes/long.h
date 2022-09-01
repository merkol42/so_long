#ifndef LONG_H
# define LONG_H

# include "../mlx/mlx.h"
# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_read(int fd, char *mystr);
char	*ft_line(char *mystr);
char	*ft_newstr(char *mystr);
// utils
int		put_string(t_game *g, char *string);
int		end_game(t_game *solong);
void	ft_error(char *str);
void	get_character_pos(t_game *solong, int which);
void	get_enemy_pos(t_player *ghost, char **map);
void	put_info(t_game *g, int y, int x);
void	set_collect(t_game *g, char which);
int		get_object_count(char **map, int which);
//map_read
char	**map_read(char *file);
char	**map_alloc(char *file);
int		line_counter(char *file);
//setup process
void	setup(t_game *solong, char *file, int bonus);
int		widht_counter(char *file);
void	fill_static_assets(t_game *solong);
//checkers
int		check_wall(char	**map);
int		check_arg(char *file);
//fill_animation
t_list	*ft_animup(t_game *g, int i);
t_list	*ft_animdown(t_game *g, int i);
t_list	*ft_animleft(t_game *g, int i);
t_list	*ft_animright(t_game *g, int i);
t_list	*ghost_up(t_game *g, int size);
t_list	*ghost_down(t_game *g, int size);
t_list	*ghost_left(t_game *g, int size);
t_list	*ghost_right(t_game *g, int size);
//draw
void	draw(t_game *g);
void	draw_map(t_game *g);
//update
void	move_player(t_game *g);
void	player_update(t_game *g);
void	update(t_game *g, int bonus);
void	update1(t_game *g);
//enemy
void	move_enemy(t_game *g);
void	enemy_update(t_game *g);
//key process
int		key_hook_bonus(int keycode, t_game *g);
int		key_hook(int keycode, t_game *g);

int		checkcolission(t_game *g, t_player *character, int direction, char c);
int		collision(t_game *solong, int x, int y, char arg);
int		get_block(t_game *solong, int x, int y, char arg);
#endif