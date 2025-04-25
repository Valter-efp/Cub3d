/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:49 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:49 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Puts a pixel of a specified color at the given coordinates in the
/// game's image.
/// @param x The x-coordinate of the pixel.
/// @param y The y-coordinate of the pixel.
/// @param color The color of the pixel in hexadecimal format.
/// @param game A pointer to the game structure containing the image data.
void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

/// @brief Clears the game's image by setting all pixels to black.
/// @param game A pointer to the game structure containing the image data.
void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}

/// @brief Calculates the distance between two points using the
// Pythagorean theorem.
/// @param x The x-coordinate of the point.
/// @param y The y-coordinate of the point.
/// @return The distance between the point and the origin.
float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

/// @brief Moves the player based on the keys that are pressed.
/// @param game A pointer to the game structure containing the player data.
/// @return Always returns 0.
float	fixed_dist(t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = game->coords.x2 - game->coords.x1;
	delta_y = game->coords.y2 - game->coords.y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

/// @brief Main drawing loop that updates the game screen.
/// @param game A pointer to the game structure.
/// @return Always returns 0.
int	draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	move_player(game);
	clear_image(game);
	if (DEBUG)
	{
		handle_debug_mode(game, player);
	}
	else
	{
		handle_normal_mode(game, player);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
