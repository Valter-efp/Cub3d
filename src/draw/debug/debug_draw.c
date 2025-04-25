/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:26 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:26 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"

float	debug_fixed_dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

bool	debug_touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	debug_put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	debug_draw_line(t_player *player, t_game *game, float ray_angle)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(ray_angle);
	sin_angle = sin(ray_angle);
	ray_x = player->x;
	ray_y = player->y;
	while (!debug_touch(ray_x, ray_y, game))
	{
		debug_put_pixel((int)ray_x, (int)ray_y, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
		if (ray_x < 0 || ray_x >= game->map_width * BLOCK || ray_y < 0
			|| ray_y >= game->map_height * BLOCK)
			break ;
	}
}

/// @brief Draws a square of a specified size and color at the given
/// coordinates in the game's image.
/// @param x The x-coordinate of the top-left corner of the square.
/// @param y The y-coordinate of the top-left corner of the square.
/// @param size The size of the square (length of one side).
/// @param color The color of the square in hexadecimal format.
/// @param game A pointer to the game structure containing the image data.
void	debug_draw_square(t_draw_params *params, t_game *game)
{
	draw_horizontal_line(params, 0, game);
	draw_vertical_line(params, 0, game);
	draw_vertical_line(params, params->size, game);
	draw_horizontal_line(params, params->size, game);
}
