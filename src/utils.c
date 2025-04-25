/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:51 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:51 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

char	*ft_strdupn(const char *str1)
{
	int		i;
	char	*dupstr;
	int		len;

	len = ft_strlen((char *)str1);
	dupstr = malloc((len + 1) * sizeof(char));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (str1[i] != '\0' && str1[i] != '\n')
	{
		dupstr[i] = str1[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

int	ft_max_width(char **map)
{
	int		i;
	size_t	max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
	}
	return (max);
}

int	ft_max_height(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	ft_strslen(char *str1)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str1[i])
	{
		if (str1[i] != ' ')
			len++;
		i++;
	}
	return (len);
}

char	*ft_strsdup(char *str1)
{
	int		i;
	int		j;
	char	*dupstr;
	int		len;

	j = -1;
	len = ft_strslen(str1);
	dupstr = malloc((len + 2) * sizeof(char));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (str1[i] == ' ')
		i++;
	i = i - 1;
	while (str1[++i] != '\0')
	{
		if (str1[i] != ' ' || (str1[i] == ' '
				&& i == 1) || (str1[i] == ' '
				&& i == 2 && str1[i - 1] != ' '))
		{
			dupstr[++j] = str1[i];
		}
	}
	dupstr[j + 1] = '\0';
	return (free(str1), dupstr);
}
