/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:42 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

/// @brief Frees the map and double pointer chars
/// @param map The map or a double pointer char
void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
		{
			free(map[i]);
		}
		free(map);
	}
}

/// @brief Frees the file in case the file is not finished
/// @param str The line it stopped
/// @param fd The file descriptor
void	ft_free_file(char *str, int fd)
{
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	ft_free_fd(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
