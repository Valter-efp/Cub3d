/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:01:12 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:44:28 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include "ctype.h"
int	main()
{
	printf("Standard isascii('V'): %d\n", isascii('V'));
	printf("Custom   isascii('V'): %d\n", ft_isascii('V'));
	return(0);
}*/