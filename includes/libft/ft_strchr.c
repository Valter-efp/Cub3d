/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:41:18 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:41:18 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (char )c != *s)
		s++;
	if (*s == (char )c || !c)
		return ((char *)s);
	++s;
	return (0);
}

/*#include "string.h"
int	main()
{
	char *s = "42 is nuts!";
	char c = 'i';
	printf("%s\n", ft_strchr(s, c));
	printf("%s", strchr(s, c));
	return(0);
}*/