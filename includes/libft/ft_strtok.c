/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:39:40 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:39:43 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *string, char s)
{
	int		i;
	char	*res;

	i = 0;
	while (string[i] != s && string[i] != '\0')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, string, i + 1);
	res[i] = '\0';
	return (res);
}
