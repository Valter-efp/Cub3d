/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:42:15 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:42:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* `ft_countw` - This fn is used to count the words in `s` delimited */
/* by `c`. Basicly each occurence after `c`is a new word */
/* `ft_wlen` - This fn is used to calculate the length of wach word in `s` */
/* `get_next_word` - Used to allocate memory for the next word */
/* returns ptr to memory position */
/* `ft_split`- splits `s`into an array of new strings. */
/* 1st we chek if `s` not null */
/* using `ft_countw` calculate nbr of words of original str */
/* the allocate new memory for the array of strings +1 for null */
/* `newstr[i] = get_next_word`- stores nxt word in the array position */
/* and cheacks if null */
#include "libft.h"

int	ft_countw(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

int	ft_wlen(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	*get_next_word(const char **s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (**s == c)
		(*s)++;
	len = ft_wlen(*s, c);
	word = (char *)malloc(sizeof(char) * (len +1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, *s, len + 1);
	*s += len;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**newstr;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = ft_countw(s, c);
	newstr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		newstr[i] = get_next_word(&s, c);
		if (!newstr[i])
		{
			while (--i >= 0)
				free(newstr[i]);
			free(newstr);
			return (NULL);
		}
		i++;
	}
	newstr[i] = NULL;
	return (newstr);
}
