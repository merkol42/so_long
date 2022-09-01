#ifndef STRUCTS_H
# define STRUCTS_H

//assets
# define WALL "./sprites/Other/Walls/wall.xpm"
# define COLLECT "./sprites/Other/Pacdots/pacdot_food.xpm"
# define EXIT "./sprites/Other/Portal/portal.xpm"
# define SIZE 32
//key_process
# define ESC 53
# define W	13
# define A	0
# define S	1
# define D	2
//player move
# define UP 1
# define DOWN 3
# define STOP 0
# define LEFT -3
# define RIGHT -1

# define MOVESPEED 8
# define ASSETSPEED 2

//img pointers
typedef struct s_assets
{
	void		*wall;
	void		*collect;
	void		*exit;
	int			size;
}	t_assets;

//map properties
typedef struct s_map
{
	char	**map;
	int		widht;
	int		height;
	int		collect;
}	t_map;

typedef struct s_player
{
	t_list		*up;
	t_list		*down;
	t_list		*left;
	t_list		*right;
	t_list		*pacmanfirst;
	t_list		*current;
	int			c_count;
	int			movedir;
	int			movetemp;
	int			y;
	int			x;
	struct s_player	*next;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_assets		*assets;
	t_map			*map;
	t_player		*player;
	t_player		*enemy;
	int				movecount;
}	t_game;


#endif