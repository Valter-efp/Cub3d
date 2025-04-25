/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:21 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:21 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"

void	draw_edges(int r[4][2], int color, t_game *game)
{
	int	i;
	int	p1[2];
	int	p2[2];

	i = 0;
	while (i < 4)
	{
		p1[0] = r[i][0];
		p1[1] = r[i][1];
		p2[0] = r[(i + 1) % 4][0];
		p2[1] = r[(i + 1) % 4][1];
		debug_draw_line_help(p1, p2, color, game);
		i++;
	}
}

void	debug_draw_rotated_square(t_square *sq, t_game *game)
{
	int	h_size;
	int	c[4][2];
	int	r[4][2];

	h_size = sq->size / 2;
	c[0][0] = -h_size;
	c[0][1] = -h_size;
	c[1][0] = h_size;
	c[1][1] = -h_size;
	c[2][0] = h_size;
	c[2][1] = h_size;
	c[3][0] = -h_size;
	c[3][1] = h_size;
	rotate_corners(c, r, sq);
	draw_edges(r, sq->color, game);
}

void	draw_horizontal_line(t_draw_params *params, int offset_y, t_game *game)
{
	int	i;

	i = 0;
	while (i < params->size)
	{
		debug_put_pixel(params->x + i, params->y + offset_y,
			params->color, game);
		i++;
	}
}

void	draw_vertical_line(t_draw_params *params, int offset_x, t_game *game)
{
	int	i;

	i = 0;
	while (i < params->size)
	{
		debug_put_pixel(params->x + offset_x, params->y + i,
			params->color, game);
		i++;
	}
}
