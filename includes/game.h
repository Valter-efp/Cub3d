/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:22:06 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/06 17:41:53 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

//Defines fo window creation
# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK 64

//Variables for debbuging
# define DEBUG 0
# define BYPASSPARSE 0
# define TEXTURE_DEBUG 0

//Defines for textures index
# define NORTH_WALL_T_I 0
# define SOUTH_WALL_T_I 1
# define WEST_WALL_T_I 2
# define EAST_WALL_T_I 3
# define DEFAULT_TEXTURE_INDEX 0

//Defines for textures debugs
# define DEBUGSWALL "[TEXTURE_DEBUG] Texture south-facing wall (north side)\n"
# define DEBUGNWALL "[TEXTURE_DEBUG] Texture north-facing wall (south side)\n"
# define DEBUGWWALL "[TEXTURE_DEBUG] Texture west-facing wall (east side)\n"
# define DEBUGEWALL "[TEXTURE_DEBUG] Texture east-facing wall (west side)\n"

//Defines for keypress
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define KEY_E 101
# define KEY_Q 113
# define ESC 65307

# define PI 3.14159265359

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <sys/stat.h>
# include <errno.h>

/// @brief Enum to represent the side of the wall hit by the ray.
typedef enum s_hit_side
{
	HIT_NORTH,
	HIT_SOUTH,
	HIT_EAST,
	HIT_WEST,
	HIT_NONE
}	t_hit_side;

/// @brief Structure to hold parameters for drawing druing debug.
typedef struct s_draw_params
{
	int	x;
	int	y;
	int	size;
	int	color;
}	t_draw_params;

/// @brief Structure to hold square information during debug.
typedef struct s_square
{
	int		x;
	int		y;
	int		size;
	float	angle;
	int		color;
}	t_square;

/// @brief Structure to hold texture state information.
typedef struct s_texture_state
{
	t_hit_side	previous_hit_side;
	int			consecutive_wall_count;
	int			previous_texture_index;
	int			previous_map_x;
	int			previous_map_y;
}	t_texture_state;

/// @brief Structure to hold coordinates.
typedef struct s_coords
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_coords;

/// @brief Structure to hold variables for drawing.
typedef struct s_draw_vars
{
	int	map_x;
	int	map_y;
	int	texture_index;
	int	tex_x;
	int	ceiling_color;
	int	floor_color;
	int	y;
}	t_draw_vars;

/// @brief Structure to hold information about a wall slice.
typedef struct s_wall_slice
{
	int		start_y;
	int		end_y;
	float	perp_dist;
	float	line_height;
}	t_wall_slice;

/// @brief Structure to hold information about the hit of the ray.
typedef struct s_hit_info
{
	float		hit_x;
	float		hit_y;
	t_hit_side	hit_side;
}	t_hit_info;

/// @brief Structure to hold ray information.
typedef struct s_ray
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	float	delta_x;
	float	delta_y;
	float	cell_x;
	float	cell_y;
}	t_ray;

typedef struct s_player
{
	char	direction;
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	t_player		player;
	void			*texture_img[4];
	char			*texture_data[4];
	int				texture_width[4];
	int				texture_height[4];
	int				texture_bpp[4];
	int				texture_size_line[4];
	int				texture_endian[4];
	char			**map;
	int				map_width;
	int				map_height;
	// RGB values for ceiling and floor colors
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	t_ray			ray;
	t_hit_info		hit_info;
	t_wall_slice	wall_slice;
	t_coords		coords;
	t_texture_state	texture_state;
	char			*path_north;
	char			*path_south;
	char			*path_west;
	char			*path_east;
}	t_game;

// Function declarations
//Draw
void	put_pixel(int x, int y, int color, t_game *game);
void	clear_image(t_game *game);
float	distance(float x, float y);
float	fixed_dist(t_game *game);
bool	touch(float px, float py, t_game *game);
int		draw_loop(t_game *game);
int		determine_texture_index(t_game *game, int map_x,
			int map_y, t_hit_side hit_side);
void	draw_line(t_game *game, float ray_angle, int screen_x);

//Draw_utils
void	draw_ceiling(t_game *game, int screen_x,
			int start_y, int ceiling_color);
void	draw_floor(t_game *game, int screen_x, int end_y, int floor_color);
void	handle_debug_mode(t_game *game, t_player *player);
void	handle_normal_mode(t_game *game, t_player *player);

//Cast_ray
void	cast_ray(t_game *game, float ray_angle);

//Draw_debug
void	debug_put_pixel(int x, int y, int color, t_game *game);
void	debug_draw_line(t_player *player, t_game *game, float ray_angle);
void	debug_draw_square(t_draw_params *params, t_game *game);
void	draw_map(t_game *game);
void	debug_draw_rotated_square(t_square *sq, t_game *game);
//Debug_draw_utils
void	draw_map(t_game *game);
void	debug_draw_line_step(int *p1, int *step, int *error, int *d);
void	debug_draw_line_help(int *p1, int *p2, int color, t_game *game);
void	rotate_point(int *p, float angle, int *r);
void	rotate_corners(int c[4][2], int r[4][2], t_square *sq);
//Debug_draw_utils2
void	draw_edges(int r[4][2], int color, t_game *game);
void	debug_draw_rotated_square(t_square *sq, t_game *game);
void	draw_horizontal_line(t_draw_params *params, int offset_y, t_game *game);
void	draw_vertical_line(t_draw_params *params, int offset_x, t_game *game);

//Parsing
int		ft_check_path(char **tmp_map, int height);
int		ft_valid_file(char **argv);
int		ft_check_assets(char **argv);
int		ft_valid_map(char **argv);
int		ft_check(int argc, char **argv);
//Parsing_utils
int		ft_check_borders_horizontal(char **tmp_map, int height);
int		ft_check_borders_vertical(char **tmp_map, int height);
char	**ft_fill_design(char **argv);
int		ft_rowlen(char *file);
int		ft_checkfile(char *file);
//Parsing_utils2
int		ft_has_sides_and_colors(int *colors, int *sides);
int		ft_check_img(char *str);
void	ft_see_assets(int **colors, int **sides, char *str);
int		ft_check_colors(char *str);
int		ft_find_path(char **map, int x, int y);
//Parsing_utils3
int		ft_check_borders(char **tmp_map, int height);
int		ft_has_hole(char **map, int x, int y, int height);
int		ft_check_holes(char **map, int height);
int		ft_get_coor(char **tmp_map, char c);
int		ft_check_unkchr(char **map);
//Parsing_utils4
int		ft_has_sides_and_colors(int *colors, int *sides);
int		ft_strlens(char *str);
int		ft_is_map(char *str);
int		ft_find_player(char **tmp_map);
int		ft_is_color(char *str);
//Parsing_utils5
char	**special_split(char *str);
int		is_config_line(char *str);
int		is_empty_line(char *str);
int		map_design(char *file);
int		ft_count_rows(char **map);

//Frees
void	ft_free_map(char **map);
void	ft_free_file(char *str, int fd);
void	ft_free_fd(int fd);

//Main
char	**get_map(char **argv);
int		close_window(t_game *game);
int		handle_key(int key, t_game *game);
int		main(int argc, char **argv);

//Init
void	init_game(t_game *game, char **argv);
char	**get_map(char **argv);
char	*ft_get_wall_path(char **argv, char *side);
void	ft_init_textures(t_game **game, char **argv);
void	ft_init_textures2(t_game ***game);

//Init
void	init_game(t_game *game, char **argv);
char	**get_map(char **argv);
char	*ft_get_wall_path(char **argv, char *side);
void	ft_init_textures(t_game **game, char **argv);
void	ft_init_textures2(t_game ***game);

//Player
bool	is_wall(float x, float y, t_game *game);
char	ft_get_dir(char **map);
void	init_player(t_player *player, char **map);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_player(t_game *game);

//Utils
char	*ft_strdupn(const char *str1);
int		ft_max_width(char **map);
int		ft_max_height(char **map);
int		ft_strslen(char *str1);
char	*ft_strsdup(char *str1);

#endif
