/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:19:31 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/11 11:09:17 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief 
/// @param game ptr to the game structure
/// @param ray_angle angle that the ray is casted
/// ray cos_angle and sin_angle are the cos and sin of the ray angle
/// ray_x and y are the starting point of the ray
/// delta_x and y are the direction of the ray
void	init_ray(t_game *game, float ray_angle)
{
	game->ray.cos_angle = cos(ray_angle);
	game->ray.sin_angle = sin(ray_angle);
	game->ray.ray_x = game->player.x;
	game->ray.ray_y = game->player.y;
	game->ray.delta_x = game->ray.cos_angle;
	game->ray.delta_y = game->ray.sin_angle;
}

/// @brief loops the ray in the direction of the delta_x and y
/// until it hits a wall
/// if the ray goes out of the map, it sets the hit_x and y to the
/// last position of the ray
/// @param game ptr to the game structure
void	perform_ray_casting(t_game *game)
{
	while (1)
	{
		game->ray.ray_x += game->ray.delta_x;
		game->ray.ray_y += game->ray.delta_y;
		if (game->ray.ray_x < 0
			|| game->ray.ray_x >= game->map_width * BLOCK
			|| game->ray.ray_y < 0
			|| game->ray.ray_y >= game->map_height * BLOCK)
		{
			game->hit_info.hit_x = game->ray.ray_x;
			game->hit_info.hit_y = game->ray.ray_y;
			return ;
		}
		if (touch(game->ray.ray_x, game->ray.ray_y, game))
			break ;
	}
	game->hit_info.hit_x = game->ray.ray_x;
	game->hit_info.hit_y = game->ray.ray_y;
}

/// @brief Compares the distance between the center of the cell and the
/// intersection point of the ray with the cell walls to determine the hit side
/// cell_x and y are the distance from the center of the cell to intersection
/// @param game 
void	determine_hit_side(t_game *game)
{
	game->ray.cell_x = fmod(game->ray.ray_x, BLOCK);
	game->ray.cell_y = fmod(game->ray.ray_y, BLOCK);
	if (fabs(game->ray.cell_x - BLOCK / 2) > fabs(game->ray.cell_y - BLOCK / 2))
	{
		if (game->ray.delta_x > 0)
			game->hit_info.hit_side = HIT_WEST;
		else
			game->hit_info.hit_side = HIT_EAST;
	}
	else
	{
		if (game->ray.delta_y > 0)
			game->hit_info.hit_side = HIT_NORTH;
		else
			game->hit_info.hit_side = HIT_SOUTH;
	}
}

/// @brief Calls helper functions to cast a ray and determine the hit side.
/// @param game ptr to the game structure
/// @param ray_angle angle that the ray is casted
void	cast_ray(t_game *game, float ray_angle)
{
	init_ray(game, ray_angle);
	game->hit_info.hit_side = HIT_NONE;
	perform_ray_casting(game);
	determine_hit_side(game);
}
