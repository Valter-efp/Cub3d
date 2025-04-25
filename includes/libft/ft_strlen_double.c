/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:58:23 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:41 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculate the length of a double pointer string array.
/// @param str The double pointer string array.
/// @return The length of the string array.
size_t	ft_strlen_double(const char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
