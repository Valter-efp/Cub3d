/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:03:48 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/14 15:29:53 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *line_buffer)
{
	char	*buffer;
	int		read_size;

	read_size = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (read_size != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (dealloc(line_buffer, buffer));
		buffer[read_size] = '\0';
		line_buffer = ft_strjoin_gnl(line_buffer, buffer);
	}
	if (read_size == -1 || *line_buffer == '\0')
		return (dealloc(line_buffer, buffer));
	free(buffer);
	return (line_buffer);
}

char	*extract_remaining_line(char *line_buffer)
{
	char	*reamining_line;

	reamining_line = ft_strndup_gnl(line_buffer
			+ ft_strclen(line_buffer, '\n') + 1,
			ft_strclen(line_buffer, '\0') - ft_strclen(line_buffer, '\n'));
	free(line_buffer);
	if (!reamining_line)
		return (NULL);
	return (reamining_line);
}

char	*get_next_line(int fd)
{
	static char		*line_buffer[MULTIPLEFD_LIMIT];
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_buffer[fd] = read_file(fd, line_buffer[fd]);
	if (!line_buffer[fd])
		return (NULL);
	new_line = ft_strndup_gnl(line_buffer[fd],
			ft_strclen(line_buffer[fd], '\n') + 1);
	if (!new_line)
		return (NULL);
	line_buffer[fd] = extract_remaining_line(line_buffer[fd]);
	if (!line_buffer[fd])
		free(line_buffer[fd]);
	return (new_line);
}
