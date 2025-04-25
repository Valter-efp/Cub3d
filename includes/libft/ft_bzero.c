/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:44:43 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:43 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function will fill "n" positions of the memory 
pointed by "s" with zero "'/0'" */
/* If "n==0" return; to handle if n=0*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	if (n == 0)
		return ;
	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
