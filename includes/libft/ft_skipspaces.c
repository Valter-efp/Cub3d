/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:57:25 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:42:23 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	skip_spaces(const char *input, size_t i)
{
	while (input[i] && input[i] == ' ')
		i++;
	return (i);
}
