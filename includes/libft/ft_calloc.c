/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:01:09 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:41 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nitems, int size)
{
	void	*str;

	str = malloc (nitems * size);
	if (!str)
		return (0);
	ft_bzero(str, size * nitems);
	return (str);
}
