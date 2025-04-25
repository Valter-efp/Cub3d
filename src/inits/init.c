/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:20:00 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/11 15:11:58 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

/// @brief Generates a hardcoded map for the game.
/// @return A pointer to the generated map array.
char	**get_map(char **argv)
{
	char	**map;

	if (BYPASSPARSE)
	{
		map = malloc(sizeof(char *) * 11);
		map[0] = "111111111111111";
		map[1] = "100000000000001";
		map[2] = "100100000000001";
		map[3] = "100000000000001";
		map[4] = "100000000000001";
		map[5] = "100000010000001";
		map[6] = "10000W000000001";
		map[7] = "100000000001101";
		map[8] = "100000000000001";
		map[9] = "111111111111111";
		map[10] = NULL;
	}
	if (!BYPASSPARSE)
	{
		map = ft_fill_design(argv);
	}
	return (map);
}

char	*ft_get_wall_path(char **argv, char *side)
{
	int		fd;
	char	*str;
	char	**lines;
	char	*path;

	path = "";
	lines = NULL;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (ft_strnstr(str, side, 1000))
		{
			lines = ft_split(str, ' ');
			path = ft_substr(lines[1], 0, ft_strclen(lines[1], '\n'));
			ft_free_map(lines);
			free(str);
			ft_free_fd(fd);
			return (path);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (close(fd), NULL);
}

int	ft_get_color(char **argv, char *side, int pricol)
{
	int		fd;
	char	*str;
	char	**lines;
	char	**rgb;
	int		color;

	color = 0;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (ft_strnstr(str, side, 1000))
		{
			str = ft_strsdup(str);
			lines = ft_split(str, ' ');
			rgb = ft_split(lines[1], ',');
			color = ft_atoi(rgb[pricol]);
			ft_free_map(lines);
			return (ft_free_map(rgb), free(str), ft_free_fd(fd), color);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (close(fd), 0);
}

/// @brief Initializes the game structure, 
/// including the player, map, and graphics.
/// @param game A pointer to the game structure to be initialized.
void	init_game(t_game *game, char **argv)
{
	game->map = get_map(argv);
	init_player(&game->player, game->map);
	game->map_width = ft_max_width(game->map);
	game->map_height = ft_max_height(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT,
			"cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	game->ceiling_r = ft_get_color(argv, "C", 0);
	game->ceiling_g = ft_get_color(argv, "C", 1);
	game->ceiling_b = ft_get_color(argv, "C", 2);
	game->floor_r = ft_get_color(argv, "F", 0);
	game->floor_g = ft_get_color(argv, "F", 1);
	game->floor_b = ft_get_color(argv, "F", 2);
	ft_init_textures(&game, argv);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	game->texture_state.previous_hit_side = -1;
	game->texture_state.previous_map_x = -1;
	game->texture_state.previous_map_y = -1;
	game->texture_state.consecutive_wall_count = 0;
	game->texture_state.previous_texture_index = DEFAULT_TEXTURE_INDEX;
}
