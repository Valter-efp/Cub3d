/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:13 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:13 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Checks the borders of the map
/// @param tmp_map The temporary map
/// @param height How many rows the map has.
/// @return Returns 0 if some checks fail. Returns 1 
/// if everything alright.
int	ft_check_borders(char **tmp_map, int height)
{
	if (!ft_check_borders_horizontal(tmp_map, height))
		return (0);
	if (!ft_check_borders_vertical(tmp_map, height))
		return (0);
	return (1);
}

/// @brief Checks if the maps some holes in the map
/// (including missing walls)
/// @param map The map
/// @param x X coordinates
/// @param y Y coordinates
/// @param height The map's height
/// @return Returns 0 if it finds some hole. Returns 1 
/// if it finds nothing wrong
int	ft_has_hole(char **map, int x, int y, int height)
{
	if ((x + 1 == (int)ft_strlen(map[y])
			|| !map[y][x + 1])
			|| (map[y][x + 1] != '1'
			&& map[y][x + 1] != 'N'
			&& map[y][x + 1] != 'S'
			&& map[y][x + 1] != 'E'
			&& map[y][x + 1] != 'W'
			&& map[y][x + 1] != '0'))
		return (1);
	if ((x == 0 || !map[y][x - 1]) || (map[y][x - 1] != '1'
			&& map[y][x - 1] != 'N' && map[y][x - 1] != 'S'
			&& map[y][x - 1] != 'E' && map[y][x - 1] != 'W'
			&& map[y][x - 1] != '0'))
		return (1);
	if ((y + 1 == height || !map[y + 1][x])
			|| (map[y + 1][x] != '1' && map[y + 1][x] != 'N'
			&& map[y + 1][x] != 'S' && map[y + 1][x] != 'E'
			&& map[y + 1][x] != 'W' && map[y + 1][x] != '0'))
		return (1);
	if ((y == 0 || !map[y - 1][x]) || (map[y - 1][x] != '1'
			&& map[y - 1][x] != 'N' && map[y - 1][x] != 'S'
			&& map[y - 1][x] != 'E' && map[y - 1][x] != 'W'
			&& map[y - 1][x] != '0'))
		return (1);
	return (0);
}

/// @brief Checks if the maps some holes in the map (including missing walls)
/// @param map The map
/// @param height The map's height
/// @return Returns 0 if some checks fail. Returns 1 
/// if everything alright.
int	ft_check_holes(char **map, int height)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
					|| map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W')
			{
				if (ft_has_hole(map, j, i, height))
					return (0);
			}
		}
	}
	return (1);
}

/// @brief Gets the player coordinates
/// @param tmp_map The temporary map
/// @param c If it "x" it will give the coordinate x of 
/// player. If "y" it will give the player's y coordinate
/// @return Returns a coordinate
int	ft_get_coor(char **tmp_map, char c)
{
	int	i;
	int	j;
	int	coor;

	i = -1;
	coor = 0;
	while (tmp_map[++i])
	{
		j = -1;
		while (tmp_map[i][++j])
		{
			if (tmp_map[i][j] == 'N' || tmp_map[i][j] == 'S'
					|| tmp_map[i][j] == 'E'
					|| tmp_map[i][j] == 'W')
			{
				if (c == 'x')
					coor = j;
				else if (c == 'y')
					coor = i;
			}
		}
	}
	return (coor);
}

/// @brief Checks if there's some unkown characters
/// @param map The map
/// @return Returns 0 if some checks fail. Returns 1 if everything alright.
int	ft_check_unkchr(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != 'N'
					&& map[i][j] != 'S' && map[i][j] != 'E'
					&& map[i][j] != 'W' && map[i][j] != '1'
					&& map[i][j] != ' ')
			{
				return (0);
			}
		}
	}
	return (1);
}
