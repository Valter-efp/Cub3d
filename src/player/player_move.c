/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:34 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:34 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Rotates the player
/// if the player is rotating left, the angle is decreased
/// if the player is rotating right, the angle is increased
/// @param game ptr to the game structure
void	rotate_player(t_game *game)
{
	float	angle_speed;

	angle_speed = 0.05;
	if (game->player.left_rotate)
		game->player.angle -= angle_speed;
	if (game->player.right_rotate)
		game->player.angle += angle_speed;
}

/// @brief Moves the player forward or backward
/// @param game ptr to the game structure
/// @param cos_angle player angle cos to calculate new X position
/// @param sin_angle player angle sin to calculate new Y position
/// is_wall checks if the player is going to hit a wall
/// @param speed speed of the player
void	move_forward_backward(t_game *game, float cos_angle, float sin_angle,
	int speed)
{
	float	new_x;
	float	new_y;

	if (game->player.key_up)
	{
		new_x = game->player.x + cos_angle * speed;
		new_y = game->player.y + sin_angle * speed;
		if (!is_wall(new_x, new_y, game))
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	if (game->player.key_down)
	{
		new_x = game->player.x - cos_angle * speed;
		new_y = game->player.y - sin_angle * speed;
		if (!is_wall(new_x, new_y, game))
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
}

/// @brief Moves the player left or right
/// @param game ptr to the game structure
/// @param cos_angle player angle cos to calculate new y position
/// @param sin_angle player angle sin to calculate new x position
/// is_wall checks if the player is going to hit a wall
/// @param speed speed of the player
void	move_left_right(t_game *game, float cos_angle, float sin_angle,
	int speed)
{
	float	new_x;
	float	new_y;

	if (game->player.key_left)
	{
		new_x = game->player.x + sin_angle * speed;
		new_y = game->player.y - cos_angle * speed;
		if (!is_wall(new_x, new_y, game))
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	if (game->player.key_right)
	{
		new_x = game->player.x - sin_angle * speed;
		new_y = game->player.y + cos_angle * speed;
		if (!is_wall(new_x, new_y, game))
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
}

/// @brief updates the player position
/// @param game ptr to the game structure
void	move_player(t_game *game)
{
	int		speed;
	float	cos_angle;
	float	sin_angle;

	speed = 6;
	rotate_player(game);
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	move_forward_backward(game, cos_angle, sin_angle, speed);
	move_left_right(game, cos_angle, sin_angle, speed);
}

/// @brief Gets the direction the playes is gonna be watching.
/// @param map The map of the game
/// @return Returns the direction of the player
char	ft_get_dir(char **map)
{
	int		i;
	int		j;
	char	dir;

	i = -1;
	dir = 'o';
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'N'
					|| map[i][j] == 'E' || map[i][j] == 'W')
				dir = map[i][j];
		}
	}
	return (dir);
}
