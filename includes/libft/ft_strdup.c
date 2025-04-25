/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:18:41 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:41:10 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Since I'll be duplicating a string better to "const" it so
I don't change it accidentally*/

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*dupstr;
	int		len;

	len = ft_strlen((char *)str1);
	dupstr = malloc((len + 1) * sizeof(char));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		dupstr[i] = str1[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

/*#include "string.h"
int       main(void)
{
	char    *str;
	char    *allocated;

	str = "Hello World with malloc()";
	printf("original  : base  : $%s$ @ %p\n", str, str);
	allocated = strdup(str);
	printf("copied    : alloc : $%s$ @ %p\n", allocated, allocated);
	allocated = ft_strdup(str);
	printf("ft_copied : alloc : $%s$ @ %p\n", allocated, allocated);
}*/