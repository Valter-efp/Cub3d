/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:38 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:38 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Checks if a point is inside a wall in the map.
/// @param x The x-coordinate of the point.
/// @param y The y-coordinate of the point.
/// @param game A pointer to the game structure containing the map data.
/// @return True if the point is inside a wall, false otherwise.
bool	is_wall(float x, float y, t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	if (map_x < 0 || map_x >= game->map_width
		|| map_y < 0 || map_y >= game->map_height)
		return (true);
	return (game->map[map_y][map_x] == '1');
}

float	ft_get_ang(char dir)
{
	if (dir == 'N')
		return (PI * 1.5);
	else if (dir == 'E')
		return (PI * 2);
	else if (dir == 'W')
		return (PI);
	else if (dir == 'S')
		return (PI / 2);
	return (0);
}

/// @brief Initializes the player structure with default values.
/// @param player A pointer to the player structure to be initialized.
void	init_player(t_player *player, char **map)
{
	player->direction = ft_get_dir(map);
	player->x = (ft_get_coor(map, 'x') * 64) + 32;
	player->y = (ft_get_coor(map, 'y') * 64) + 32;
	player->angle = ft_get_ang(player->direction);
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

/// @brief Handles key press events and updates the 
/// player's movement and rotation flags.
/// @param keycode The key code of the pressed key.
/// @param player A pointer to the player structure.
/// @return Always returns 0.
int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == LEFT || keycode == KEY_Q)
		game->player.left_rotate = true;
	if (keycode == RIGHT || keycode == KEY_E)
		game->player.right_rotate = true;
	if (keycode == ESC)
		close_window(game);
	return (0);
}

/// @brief Handles key release events and updates 
///	the player's movement and rotation flags.
/// @param keycode The key code of the released key.
/// @param player A pointer to the player structure.
/// @return Always returns 0.
int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == D)
		game->player.key_right = false;
	if (keycode == LEFT || keycode == KEY_Q)
		game->player.left_rotate = false;
	if (keycode == RIGHT || keycode == KEY_E)
		game->player.right_rotate = false;
	return (0);
}
