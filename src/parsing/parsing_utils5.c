/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:20:21 by vafernan          #+#    #+#             */
/*   Updated: 2025/03/11 14:45:14 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	**special_split(char *str)
{
	char	*dummy;
	char	**result;
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	dummy = ft_strsdup(ft_strdupn(&str[i]));
	result = ft_split(dummy, ' ');
	return (free(dummy), result);
}

int	is_config_line(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0
		|| ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0);
}

int	is_empty_line(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	map_design(char *file)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_perror("Error\nFailed to open file\n"), -1);
	str = get_next_line(fd);
	while (str)
	{
		if (!is_config_line(str) && !is_empty_line(str))
			i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_count_rows(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}
