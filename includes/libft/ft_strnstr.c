/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:03 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:03 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function will search for the "needle" string on the "haystack"
//string until the desirable length of "haystack" with "len"
// If "needle" is the empty string, the return value is always haystack itself.
// The first loop iterates through "haystack" untill '\0' or "len" is reached
// The second loop compares "haystack" and "needle" while they match and
//"len" is not reached~
// If total match is found it return a pointer to the start of
//"needle" in "haystack"
// If no match is there, "j" is set back to zero and starts again, this
//repeats as many times as "i" is less then "len"
// and then returns zero in case of no match

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *) haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle [j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *) &haystack[i]);
			}
			j ++;
		}
		j = 0;
		i++;
	}
	return (0);
}
