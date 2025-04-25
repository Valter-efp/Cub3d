/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:20:09 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/11 14:47:09 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Checks if the images is correct
/// @param str The line with the image path
/// @return Returns 0 if some check fails. Returns 1 if everything alright
int	ft_check_img(char *str)
{
	char	**img;
	char	*xpm;
	char	*path;
	int		fd;
	char	*dummy;

	dummy = ft_strsdup(ft_strdup(&str[ft_strlens(str)]));
	img = ft_split(dummy, ' ');
	xpm = ft_substr(dummy, ft_strlen(dummy) - 5, 4);
	free(dummy);
	if (!img[1])
		return (ft_free_map(img), free(xpm), 0);
	path = ft_substr(img[1], 0, ft_strclen(img[1], '\n'));
	if (!ft_strncmp(img[1], ".xpm", 4))
		return (ft_free_map(img), free(xpm), free(path), 0);
	if (ft_strcmp(xpm, ".xpm"))
		return (ft_free_map(img), free(xpm), free(path), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (ft_free_map(img), free(xpm), free(path), 0);
	}
	return (ft_free_map(img), free(xpm), free(path), 1);
}

int	ft_check_design(char *str, char *symbol, int nbr)
{
	int		result;
	char	*dummy;
	int		i;

	i = 0;
	result = 1;
	if (ft_strchr(str, 'F') || ft_strchr(str, 'C')
		|| ft_strnstr(str, "NO", 1000)
		|| ft_strnstr(str, "SO", 1000)
		|| ft_strnstr(str, "WE", 1000)
		|| ft_strnstr(str, "EA", 1000))
	{
		while (str[i] == ' ')
			i++;
		dummy = ft_strsdup(ft_strdupn(&str[i]));
		result = ft_strncmp(dummy, symbol, nbr);
		free(dummy);
	}
	return (result);
}

/// @brief Checks colors, sides and the image path
/// @param colors The colors to use on the map
/// @param sides The textures of the sides
/// @param str The line with the image path
/// @return Returns 0 if some check fails. Returns 1 if everything alright
void	ft_see_assets(int **colors, int **sides, char *str)
{
	if (!ft_check_design(str, "NO", 2) && ft_check_img(str))
		sides[0][0] += 1;
	else if (!ft_check_design(str, "SO", 2) && ft_check_img(str))
		sides[0][1] += 1;
	else if (!ft_check_design(str, "WE", 2) && ft_check_img(str))
		sides[0][2] += 1;
	else if (!ft_check_design(str, "EA", 2) && ft_check_img(str))
		sides[0][3] += 1;
	else if (!ft_check_design(str, "F", 1) && ft_check_colors(str))
		colors[0][0] += 1;
	else if (!ft_check_design(str, "C", 1) && ft_check_colors(str))
		colors[0][1] += 1;
}

/// @brief Checks if the colors are correct
/// @param str The line with the colors path
/// @return Returns 0 if some check fails. Returns 1 if everything alright
int	ft_check_colors(char *str)
{
	char	**first_split;
	char	**second_split;
	int		i;

	i = -1;
	first_split = special_split(str);
	second_split = ft_split(first_split[1], ',');
	if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
	{
		while (++i < 3)
		{
			if (!ft_is_color(second_split[i]) || ft_atoi(second_split[i]) > 255
				|| ft_atoi(second_split[i]) < 0)
			{
				if (second_split)
					ft_free_map(second_split);
				return (ft_free_map(first_split), 0);
			}
		}
	}
	if (first_split)
		ft_free_map(first_split);
	if (second_split)
		ft_free_map(second_split);
	return (1);
}

/// @brief Checks if the player has a good path
/// (while the game doesn't have a end it doesn't do much)
/// @param map The map
/// @param x X coordinates
/// @param y Y coordinates
/// @return Returns 0 if it doesn't found nothing 
/// wrong and returns 1 if it founds something wrong
int	ft_find_path(char **map, int x, int y)
{
	static int	change;

	if (change)
		return (1);
	if (!map[y][x])
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	change = ft_find_path(map, x - 1, y);
	change = ft_find_path(map, x, y - 1);
	change = ft_find_path(map, x + 1, y);
	change = ft_find_path(map, x, y + 1);
	return (change);
}
