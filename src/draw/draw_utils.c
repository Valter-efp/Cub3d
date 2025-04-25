/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:45 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:45 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief  Draws the ceiling of the game screen.
/// @param game pointer to the game structure.
/// @param screen_x The x-coordinate of the screen.
/// @param start_y The y-coordinate of the start of the ceiling.
/// @param ceiling_color The color of the ceiling.
void	draw_ceiling(t_game *game, int screen_x, int start_y, int ceiling_color)
{
	int	y;

	y = 0;
	while (y < start_y)
	{
		put_pixel(screen_x, y, ceiling_color, game);
		y++;
	}
}

/// @brief Draws the floor of the game screen.
/// @param game pointer to the game structure.
/// @param screen_x The x-coordinate of the screen.
/// @param end_y The y-coordinate of the end of the floor.
/// @param floor_color The color of the floor.
void	draw_floor(t_game *game, int screen_x, int end_y, int floor_color)
{
	int	y;

	y = end_y;
	while (y < HEIGHT)
	{
		put_pixel(screen_x, y, floor_color, game);
		y++;
	}
}

/// @brief Checks if a point touches a wall in the map.
/// @param px The x-coordinate of the point.
/// @param py The y-coordinate of the point.
/// @param game A pointer to the game structure containing the map data.
/// @return True if the point touches a wall, false otherwise.
bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	handle_debug_mode(t_game *game, t_player *player)
{
	float		fov;
	float		angle_increment;
	float		start_angle;
	int			i;
	t_square	square;

	square.x = player->x;
	square.y = player->y;
	square.size = 10;
	square.angle = player->angle;
	debug_draw_rotated_square(&square, game);
	draw_map(game);
	fov = PI / 3;
	angle_increment = fov / 50.0f;
	start_angle = player->angle - fov / 2.0f;
	i = 0;
	while (i < 50)
	{
		debug_draw_line(player, game, start_angle + i * angle_increment);
		i++;
	}
}

/// @brief Run the game in normal mode.
/// @param game ptr to the game structure
/// @param player ptr to the player structure
/// fraction is the increment for each columm of the indow (60deg)
/// fraction is the FOV
/// start_x is the start angle of the FOV
/// i is the index of the column
void	handle_normal_mode(t_game *game, t_player *player)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
}
