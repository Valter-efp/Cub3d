/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:39:47 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:39:47 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char const *s, char const c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s;
	int		size;
	char	*newstring;

	size = ft_strlen(s1);
	i = 0;
	s = 0;
	while (s1[s] && ft_check(set, s1[s]))
		s++;
	while (size > s && ft_check(set, s1[size - 1]))
		size--;
	newstring = (char *)malloc(sizeof(char) * (size - s + 1));
	if (!newstring)
		return (0);
	while (size > s)
	{
		newstring[i] = s1[s];
		i++;
		s++;
	}
	newstring[i] = '\0';
	return (newstring);
}
