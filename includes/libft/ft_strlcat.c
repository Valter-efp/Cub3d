/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:51:46 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:53 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

/*#include "string.h"

 int main(void)
{
	const char src1[10]	= "31";
	char dest1[10]   = "123";

	char src[10]	= "31";
	char dest[10]	= "123";

	size_t 			nb = 2;
	unsigned int 	nb2 = 2;
	printf("Str: %d \n", strlcat(dest1, src1, nb));
	printf("Str: %zu", ft_strlcat(dest, src, nb2));
	return (0);
}*/