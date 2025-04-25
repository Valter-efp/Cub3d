/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:17 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:17 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Checks if the colors and sides are correct
/// @param colors The colors to use on the map
/// @param sides The textures of the sides
/// @return Returns 0 if some check fails. Returns 1 if everything alright
int	ft_has_sides_and_colors(int *colors, int *sides)
{
	int	i;

	i = -1;
	while (++i <= 1)
	{
		if (!colors[i] || colors[i] != 1)
			return (ft_perror("Error\nColors problem\n"), 0);
	}
	i = -1;
	while (++i <= 3)
	{
		if (!sides[i] || sides[i] != 1)
			return (ft_perror("Error\nSides problem\n"), 0);
	}
	return (1);
}

int	ft_strlens(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	ft_is_map(char *str)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	if (!str)
		return (0);
	while (str[++i] && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != ' ' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != 'N'
			&& str[i] != 'S')
			return (0);
		if (str[i] == '1')
			check = 1;
	}
	if (!check)
		return (0);
	return (1);
}

int	ft_find_player(char **tmp_map)
{
	int	i;
	int	j;
	int	result;

	i = -1;
	result = 0;
	while (tmp_map[++i])
	{
		j = -1;
		while (tmp_map[i][++j])
		{
			if (tmp_map[i][j] == 'N' || tmp_map[i][j] == 'S'
					|| tmp_map[i][j] == 'W' || tmp_map[i][j] == 'E')
				result += 1;
		}
	}
	return (result);
}

int	ft_is_color(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}
