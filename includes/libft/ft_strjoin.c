/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:56 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:56 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1st IF - checks if any string is NULL */
/* We create "temp" with a malloc with the len of the combined
strings +1 for '\0' - If that is NULL we return NULL */
/* 1st While if s1 is valid we write temp postions to be the same
as s1 */
/* 2nd While if s2 is valid we write temp postions to be the same
as s2 */
/* Then we terminate with '\0' and return the new string */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (temp);
}
