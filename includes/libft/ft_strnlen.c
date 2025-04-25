/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:53:55 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:14 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (len < n && s[len] != '\0')
	{
		len++;
	}
	return (len);
}
