/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:19:35 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/10 17:36:32 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Handles the case where the wall is at the edge of the map.
/// @param game A pointer to the game structure.
/// @param map_x The x-coordinate of the wall in the map.
/// @param map_y The y-coordinate of the wall in the map.
/// @return The index of the texture to use.
int	handle_hard_case(t_game *game, int map_x, int map_y)
{
	if (map_y > 0 && game->map[map_y - 1][map_x] == '0')
	{
		if (TEXTURE_DEBUG)
			printf("[TEXTURE_DEBUG] Texture north (hard case)\n");
		return (NORTH_WALL_T_I);
	}
	else if (map_y < game->map_height - 1 && game->map[map_y + 1][map_x] == '0')
	{
		if (TEXTURE_DEBUG)
			printf("[TEXTURE_DEBUG] Texture south (hard case)\n");
		return (SOUTH_WALL_T_I);
	}
	else if (map_x > 0 && game->map[map_y][map_x - 1] == '0')
	{
		if (TEXTURE_DEBUG)
			printf("[TEXTURE_DEBUG] Texture west (hard case)\n");
		return (WEST_WALL_T_I);
	}
	else if (map_x < game->map_width - 1 && game->map[map_y][map_x + 1] == '0')
	{
		if (TEXTURE_DEBUG)
			printf("[TEXTURE_DEBUG] Texture east (hard case)\n");
		return (EAST_WALL_T_I);
	}
	return (-1);
}

/// @brief Handles the case where the wall is consecutive to the previous wall.
/// @param game A pointer to the game structure.
/// @param map_x The x-coordinate of the wall in the map.
/// @param map_y The y-coordinate of the wall in the map.
/// @param hit_side The side of the wall that was hit.
/// @return The index of the texture to use.
int	handle_consecutive_walls(t_game *game, int map_x, int map_y,
	t_hit_side hit_side)
{
	if (hit_side == game->texture_state.previous_hit_side
		&& ((map_x == game->texture_state.previous_map_x
				&& abs(map_y - game->texture_state.previous_map_y) == 1)
			|| (map_y == game->texture_state.previous_map_y
				&& abs(map_x - game->texture_state.previous_map_x) == 1)))
	{
		(game->texture_state.consecutive_wall_count)++;
	}
	else
	{
		game->texture_state.consecutive_wall_count = 1;
		game->texture_state.previous_hit_side = hit_side;
	}
	if (game->texture_state.consecutive_wall_count > 1
		&& game->texture_state.previous_texture_index
		!= DEFAULT_TEXTURE_INDEX)
	{
		if (TEXTURE_DEBUG)
			printf("[TEXTURE_DEBUG] Forced texture (consecutive walls)\n");
		game->texture_state.previous_map_x = map_x;
		game->texture_state.previous_map_y = map_y;
		return (game->texture_state.previous_texture_index);
	}
	return (-1);
}

/// @brief Gets the index of the texture based on the side of the wall
/// that was hit.
/// @param hit_side The side of the wall that was hit.
/// @return The index of the texture to use.
int	get_texture_index(t_hit_side hit_side)
{
	if (hit_side == HIT_NORTH)
	{
		if (TEXTURE_DEBUG)
			printf(DEBUGSWALL);
		return (NORTH_WALL_T_I);
	}
	else if (hit_side == HIT_SOUTH)
	{
		if (TEXTURE_DEBUG)
			printf(DEBUGNWALL);
		return (SOUTH_WALL_T_I);
	}
	else if (hit_side == HIT_EAST)
	{
		if (TEXTURE_DEBUG)
			printf(DEBUGWWALL);
		return (EAST_WALL_T_I);
	}
	else if (hit_side == HIT_WEST)
	{
		if (TEXTURE_DEBUG)
			printf(DEBUGEWALL);
		return (WEST_WALL_T_I);
	}
	return (DEFAULT_TEXTURE_INDEX);
}

/// @brief Determines the index of the texture to use for a wall.
/// @param game Pointer to the game structure.
/// @param map_x The x-coordinate of the wall in the map.
/// @param map_y The y-coordinate of the wall in the map.
/// @param hit_side The side of the wall that was hit.
/// @return The index of the texture to use.
int	determine_texture_index(t_game *game, int map_x, int map_y,
	t_hit_side hit_side)
{
	int	texture_index;

	if (map_x == 0 || map_y == 0 || map_x == game->map_width - 1
		|| map_y == game->map_height - 1)
	{
		if (map_y >= game->map_height || map_x >= game->map_width)
			return (-1);
		texture_index = handle_hard_case(game, map_x, map_y);
		if (texture_index != -1)
			return (texture_index);
	}
	texture_index = handle_consecutive_walls(game, map_x, map_y, hit_side);
	if (texture_index != -1)
		return (texture_index);
	texture_index = get_texture_index(hit_side);
	game->texture_state.previous_texture_index = texture_index;
	game->texture_state.previous_map_x = map_x;
	game->texture_state.previous_map_y = map_y;
	return (texture_index);
}
