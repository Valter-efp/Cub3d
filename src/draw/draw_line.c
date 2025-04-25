/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:19:41 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/11 11:18:38 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief determines the dimensions of the wall slice to draw.
/// @param game  Pointer to the game structure.
void	get_wall_slice_dimension(t_game *game)
{
	game->coords.x1 = game->player.x;
	game->coords.y1 = game->player.y;
	game->coords.x2 = game->hit_info.hit_x;
	game->coords.y2 = game->hit_info.hit_y;
	game->wall_slice.perp_dist = fixed_dist(game);
	game->wall_slice.line_height = (BLOCK / (game->wall_slice.perp_dist))
		* (WIDTH / 2);
	game->wall_slice.start_y = (HEIGHT - game->wall_slice.line_height) / 2;
	game->wall_slice.end_y = game->wall_slice.start_y
		+ game->wall_slice.line_height;
}

/// @brief Determines the x-coordinate in the texture based on the hit point.
/// @param game ptr to the game structure
/// @param texture_index the index of the txture to be used
/// @param hit_x coord of the hit point
/// @param hit_y coord of the hit point
/// @return Texture to be used
int	calculate_texture_x(t_game *game, int texture_index, float hit_x,
	float hit_y)
{
	float	wall_x;

	if (texture_index == 0 || texture_index == 1)
		wall_x = fmod(hit_x, BLOCK) / BLOCK;
	else
		wall_x = fmod(hit_y, BLOCK) / BLOCK;
	return ((int)(wall_x * game->texture_width[texture_index]));
}

/// @brief Draws a vertical stripe of a wall texture on the screen.
/// @param game Pointer to the game structure.
/// @param texture_index Index of the texture to use.
/// @param tex_x The x-coordinate in the texture to sample.
/// @param screen_x The x-coordinate on the screen where the stripe is drawn.
void	draw_vertical_stripe(t_game *game, int texture_index, int tex_x,
	int screen_x)
{
	int	tex_y;
	int	color;
	int	y;
	int	inverted_tex_x;

	y = game->wall_slice.start_y;
	while (y < game->wall_slice.end_y)
	{
		tex_y = ((y - game->wall_slice.start_y)
				* game->texture_height[texture_index]) / (game->wall_slice.end_y
				- game->wall_slice.start_y);
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= game->texture_height[texture_index])
			tex_y = game->texture_height[texture_index] - 1;
		if (texture_index == NORTH_WALL_T_I || texture_index == EAST_WALL_T_I)
			inverted_tex_x = game->texture_width[texture_index] - 1 - tex_x;
		else
			inverted_tex_x = tex_x;
		color = *(int *)(game->texture_data[texture_index]
				+ (tex_y * game->texture_size_line[texture_index]
					+ inverted_tex_x * (game->texture_bpp[texture_index] / 8)));
		put_pixel(screen_x, y, color, game);
		y++;
	}
}

/// @brief Draws a vertical line (wall slice) on the screen.
/// @param game Pointer to the game structure.
/// @param ray_angle The angle of the ray being cast.
/// @param screen_x The x-coordinate on the screen where this stripe is drawn.
void	draw_line(t_game *game, float ray_angle, int screen_x)
{
	t_draw_vars	vars;

	cast_ray(game, ray_angle);
	get_wall_slice_dimension(game);
	vars.map_x = (int)(game->hit_info.hit_x / BLOCK);
	vars.map_y = (int)(game->hit_info.hit_y / BLOCK);
	vars.texture_index = determine_texture_index(game, vars.map_x,
			vars.map_y, game->hit_info.hit_side);
	vars.tex_x = calculate_texture_x(game, vars.texture_index,
			game->hit_info.hit_x, game->hit_info.hit_y);
	vars.ceiling_color = (game->ceiling_r << 16) | (game->ceiling_g << 8)
		| game->ceiling_b;
	draw_ceiling(game, screen_x, game->wall_slice.start_y, vars.ceiling_color);
	if (vars.texture_index < 0)
		vars.texture_index = 0;
	if (vars.texture_index > 64)
		vars.texture_index = 64;
	if (vars.tex_x < 0)
		vars.tex_x = 0;
	if (vars.tex_x > 64)
		vars.tex_x = 64;
	draw_vertical_stripe(game, vars.texture_index, vars.tex_x, screen_x);
	vars.floor_color = (game->floor_r << 16) | (game->floor_g << 8)
		| game->floor_b;
	draw_floor(game, screen_x, game->wall_slice.end_y, vars.floor_color);
}
