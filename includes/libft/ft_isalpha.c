/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:15:43 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:44:32 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Lets try to start working without {} on ifs, and also without else :)*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*#include "ctype.h"
int   main()
{
	printf("Standard isalpha('V'): %d\n", isalpha('V'));
    printf("Standard isalpha('v'): %d\n", isalpha('v'));
    printf("Standard isalpha('4'): %d\n", isalpha('4'));
    printf("Standard isalpha('2'): %d\n", isalpha('2'));
    printf("Standard isalpha('!'): %d\n", isalpha('!'));
    printf("Standard isalpha('*'): %d\n", isalpha('*'));
    printf("Custom ft_isalpha('V'): %d\n", ft_isalpha('V'));
    printf("Custom ft_isalpha('v'): %d\n", ft_isalpha('v'));
    printf("Custom ft_isalpha('4'): %d\n", ft_isalpha('4'));
    printf("Custom ft_isalpha('2'): %d\n", ft_isalpha('2'));
    printf("Custom ft_isalpha('!'): %d\n", ft_isalpha('!'));
    printf("Custom ft_isalpha('*'): %d\n", ft_isalpha('*'));
	return(0);
}*/
