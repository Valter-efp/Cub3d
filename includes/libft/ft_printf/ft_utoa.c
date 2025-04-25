/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:08:45 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:13 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_usize(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_utoa(unsigned int nbr)
{
	char	*newstr;
	int		size;
	int		printed_chars;

	size = ft_usize(nbr);
	newstr = (char *)malloc(sizeof(char) * (1 + size));
	if (!newstr)
		return (0);
	newstr[size] = '\0';
	while (nbr != 0)
	{
		size--;
		newstr[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	printed_chars = ft_putstr_printf(newstr);
	free(newstr);
	return (printed_chars);
}
