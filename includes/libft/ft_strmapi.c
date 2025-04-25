/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:28 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:28 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// res= we typecast the pointer return by malloc to the data
// type we will be storing
// in the memory block. Then on the size of the block sizeof
// operator
// is used to the system size of the data type we use, we the
// multiply
// by the lenght +1 for null terminator

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s || !res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
