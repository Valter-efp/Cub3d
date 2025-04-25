/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:31 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:31 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Here Im'm not dealing with sgmentation fault. */
/* Example, in test case change 'n' to '4' and '!' is
not present - seg error occurs */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		i++;
		if (*(ptr++) == (unsigned char)c)
			return ((void *)--ptr);
	}
	return (0);
}

/*#include "string.h"
int main()
{
	char str[] = "42 is nuts! 42 yay!";
	char *ptr;
	
	ptr = memchr(str, '!', 12);
	if (ptr != NULL)
		printf("Standard memchr result: Found '%c' \n", *ptr);
	else
		printf("Character not found using Standard memchr.\n");

	ptr = ft_memchr(str, '!', 12);
	if (ptr != NULL)
		printf("Custom ft_memchr result: Found '%c'\n", *ptr);
	else
		printf("Character not found using custom ft_memchr.\n");

	return (0);
}*/