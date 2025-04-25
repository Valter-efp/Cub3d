/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:05 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:05 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"

/// @brief Draws the map by iterating through the map array and drawing
/// squares for each '1' character.
/// @param game A pointer to the game structure containing the map data.
void	draw_map(t_game *game)
{
	char			**map;
	int				y;
	int				x;
	t_draw_params	params;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				params.x = x * BLOCK;
				params.y = y * BLOCK;
				params.size = BLOCK;
				params.color = 0x0000FF;
				debug_draw_square(&params, game);
			}
			x++;
		}
		y++;
	}
}

void	debug_draw_line_step(int *p1, int *step, int *error, int *d)
{
	int	error2;

	error2 = 2 * (*error);
	if (error2 > -d[1])
	{
		*error -= d[1];
		p1[0] += step[0];
	}
	if (error2 < d[0])
	{
		*error += d[0];
		p1[1] += step[1];
	}
}

void	debug_draw_line_help(int *p1, int *p2, int color, t_game *game)
{
	int	d[2];
	int	step[2];
	int	error;

	d[0] = abs(p2[0] - p1[0]);
	d[1] = abs(p2[1] - p1[1]);
	if (p1[0] < p2[0])
		step[0] = 1;
	else
		step[0] = -1;
	if (p1[1] < p2[1])
		step[1] = 1;
	else
		step[1] = -1;
	error = d[0] - d[1];
	while (1)
	{
		debug_put_pixel(p1[0], p1[1], color, game);
		if (p1[0] == p2[0] && p1[1] == p2[1])
			break ;
		debug_draw_line_step(p1, step, &error, d);
	}
}

void	rotate_point(int *p, float angle, int *r)
{
	r[0] = (int)(p[0] * cos(angle) - p[1] * sin(angle));
	r[1] = (int)(p[0] * sin(angle) + p[1] * cos(angle));
}

void	rotate_corners(int c[4][2], int r[4][2], t_square *sq)
{
	int	i;
	int	cx;
	int	cy;

	cx = sq->x;
	cy = sq->y;
	i = 0;
	while (i < 4)
	{
		rotate_point(c[i], sq->angle, r[i]);
		r[i][0] += cx;
		r[i][1] += cy;
		i++;
	}
}
