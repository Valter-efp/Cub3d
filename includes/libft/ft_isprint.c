/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:03:40 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:44:22 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include "ctype.h"
int	main()
{
	printf("Standard isprint('V'): %d\n", isprint('V'));
	printf("Custom   isprint('V'): %d\n", ft_isprint('V'));
	printf("Standard isprint('ACKNOWLEDGE = 6'): %d\n", isprint(6));
	printf("Custom   isprint('ACKNOWLEDGE = 6'): %d\n", ft_isprint(6));
	return(0);
}*/