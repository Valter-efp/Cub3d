/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:19:56 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:19:56 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	ft_init_textures2(t_game ***game)
{
	(**game)->texture_img[0] = mlx_xpm_file_to_image((**game)->mlx,
			(**game)->path_north, &(**game)->texture_width[0],
			&(**game)->texture_height[0]);
	(**game)->texture_data[0] = mlx_get_data_addr((**game)->texture_img[0],
			&(**game)->texture_bpp[0], &(**game)->texture_size_line[0],
			&(**game)->texture_endian[0]);
	(**game)->texture_img[1] = mlx_xpm_file_to_image((**game)->mlx,
			(**game)->path_south, &(**game)->texture_width[1],
			&(**game)->texture_height[1]);
	(**game)->texture_data[1] = mlx_get_data_addr((**game)->texture_img[1],
			&(**game)->texture_bpp[1], &(**game)->texture_size_line[1],
			&(**game)->texture_endian[1]);
	(**game)->texture_img[2] = mlx_xpm_file_to_image((**game)->mlx,
			(**game)->path_west, &(**game)->texture_width[2],
			&(**game)->texture_height[2]);
	(**game)->texture_data[2] = mlx_get_data_addr((**game)->texture_img[2],
			&(**game)->texture_bpp[2], &(**game)->texture_size_line[2],
			&(**game)->texture_endian[2]);
	(**game)->texture_img[3] = mlx_xpm_file_to_image((**game)->mlx,
			(**game)->path_east, &(**game)->texture_width[3],
			&(**game)->texture_height[3]);
	(**game)->texture_data[3] = mlx_get_data_addr((**game)->texture_img[3],
			&(**game)->texture_bpp[3], &(**game)->texture_size_line[3],
			&(**game)->texture_endian[3]);
}

void	ft_init_textures(t_game **game, char **argv)
{
	(*game)->path_north = ft_get_wall_path(argv, "NO");
	(*game)->path_south = ft_get_wall_path(argv, "SO");
	(*game)->path_west = ft_get_wall_path(argv, "WE");
	(*game)->path_east = ft_get_wall_path(argv, "EA");
	ft_init_textures2(&game);
}
