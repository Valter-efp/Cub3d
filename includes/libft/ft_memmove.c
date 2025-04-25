/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:09 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:09 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void *memmove(void dest[.n], const void src[.n], size_t n)*/
/* The previous was the way the original FN is declared on the manual
the difference is that it adds a limit to the array position "n"*/
/* This notation isn't standard in C, so it might lead to compatibility 
issues with compilers that don't support it or treat it differently. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < n)
	{
		i = n -1;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*#include "string.h"
int	main()
{
	char str1[20] = "42";
	char str2[] = "is nuts!";
	printf("Str1 = %s\n", str1);
	printf("Str2 = %s\n", str2);
	ft_memmove(str1 + 2, str2, 8);
	printf("Dest after custom memmove = %s\n", str1);
	memmove(str1 + 2, str2, 8);
	printf("Dest after standard memmove = %s", str1);
	return (0);
}*/