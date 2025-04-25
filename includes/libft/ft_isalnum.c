/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:34:49 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:44:35 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*#include "ctype.h"
int   main()
{
	printf("Standard isalnum('V'):%d\n", isalnum('V'));
	printf("Standard isalnum('v'):%d\n", isalnum('v'));
	printf("Standard isalnum('4'):%d\n", isalnum('4'));
	printf("Standard isalnum('2'):%d\n", isalnum('2'));
	printf("Standard isalnum('!'):%d\n", isalnum('!'));
	printf("Standard isalpha('*'):%d\n", isalnum('*'));
	printf("Custom isalnum('V'):%d\n", ft_isalnum('V'));
	printf("Custom isalnum('v'):%d\n", ft_isalnum('v'));
	printf("Custom isalnum('4'):%d\n", ft_isalnum('4'));
	printf("Custom isalnum('2'):%d\n", ft_isalnum('2'));
	printf("Custom isalnum('!'):%d\n", ft_isalnum('!'));
	printf("Custom isalnum('*'):%d\n", ft_isalnum('*'));
	return(0);
}*/