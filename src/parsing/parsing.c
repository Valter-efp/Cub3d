/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:28 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:28 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Checks the path has a cornered path
/// @param tmp_map The map
/// @param height The map's height
/// @return Returns 0 if some check fails. Returns 1 if everything alright
int	ft_check_path(char **tmp_map, int height)
{
	int	x;
	int	y;

	if (ft_find_player(tmp_map) != 1)
		return (ft_perror("Error\nProblem with player\n"), 0);
	x = ft_get_coor(tmp_map, 'x');
	y = ft_get_coor(tmp_map, 'y');
	if (!ft_check_unkchr(tmp_map))
		return (ft_perror("Error\nFound an unknow character in the map.\n"), 0);
	if (!ft_check_borders(tmp_map, height))
		return (ft_perror("Error\nSomething wrong with borders\n"), 0);
	if (!ft_check_holes(tmp_map, height))
		return (ft_perror("Error\nFound a hole in your map.\n"), 0);
	if (ft_find_path(tmp_map, x, y))
		return (ft_perror("Error\nTheres a missing wall.\n"), 0);
	return (1);
}

/// @brief Checks if the path is valid
/// @param argv The arguments. -_-
/// @return Returns 0 if map's not valid else returns 1.
int	ft_valid_file(char **argv)
{
	int	fd;

	if (!ft_strncmp(argv[1], ".cub", 4))
		return (ft_perror("Error\nMust be something.cub\n"), 0);
	if (!ft_checkfile(argv[1]))
		return (ft_perror("Error\nThe map must be .cub\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_perror("Error\nMap not found\n"), 0);
	return (1);
}

/// @brief Checks if the assets likes images and 
/// colors of floor and ceiling exist and are correct
/// @param argv The arguments. -_-
/// @return Returns 0 if some check fails. Returns 1 if everything alright.
int	ft_check_assets(char **argv)
{
	int		fd;
	char	*str;
	int		*colors;
	int		*sides;

	colors = malloc(sizeof(int) * 2);
	sides = malloc(sizeof(int) * 4);
	colors = ft_memset(colors, 0, sizeof(int) * 2);
	sides = ft_memset(sides, 0, sizeof(int) * 4);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str && (str[0] != '1' && str[0] != '0'))
	{
		if (!(str))
			return (ft_perror("Error\nAssets problem\n"), ft_free_file(str, fd),
				free(colors), free(sides), 0);
		ft_see_assets(&colors, &sides, str);
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		ft_free_file(str, fd);
	if (!ft_has_sides_and_colors(colors, sides))
		return (free(colors), free(sides), 0);
	return (free(colors), free(sides), 1);
}

/// @brief Sees if the map is valid
/// @param argv The arguments. -_-
/// @return Returns 0 if some checks fail. Returns 1 if everything alright.
int	ft_valid_map(char **argv)
{
	char	**tmp_map;
	int		height;
	int		tmp_map_height;

	tmp_map = ft_fill_design(argv);
	if (!tmp_map)
		return (0);
	tmp_map_height = ft_count_rows(tmp_map);
	height = map_design(argv[1]);
	if (tmp_map_height != height)
	{
		ft_free_map(tmp_map);
		return (ft_perror("Error\nInvalid char on map\n"), 0);
	}
	if (!ft_check_path(tmp_map, height))
		return (ft_free_map(tmp_map), 0);
	return (ft_free_map(tmp_map), 1);
}

/// @brief Calls all the checks functions to see 
/// if everything is ready for the game to start.
/// @param argc The number of arguments.
/// @param argv The arguments. -_-
/// @return Returns 0 if some checks fail. Returns 1 if everything alright.
int	ft_check(int argc, char **argv)
{
	if (argc != 2)
		return (ft_perror("Error\nI need the executable and the map\n"), 0);
	if (!ft_valid_file(argv))
		return (0);
	if (!ft_check_assets(argv))
		return (0);
	if (!ft_valid_map(argv))
		return (0);
	return (1);
}
