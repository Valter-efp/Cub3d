/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:44:08 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:08 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*array_isr(char *c, unsigned int nbr, size_t len)
{
	while (nbr > 0)
	{
		c[len--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (c);
}

static size_t	length_size(long i)
{
	int	length;

	length = 0;
	if (i <= 0)
		length = 1;
	while (i != 0)
	{
		length++;
		i = i / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	nbr;
	char			*c;
	size_t			len;

	sign = 1;
	len = length_size(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!(c))
		return (NULL);
	c[len--] = '\0';
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		nbr = n * -1;
		c[0] = '-';
	}
	else
		nbr = n;
	c = array_isr(c, nbr, len);
	return (c);
}

/*#include <stdlib.h>
int main()
{
	int num1;
	int num2;
	int num3;
	char *str1;
	char *str2;
	char *str3;

	num1 = 123;
	num2 = -456;
	num3 = 0;
	str1 = ft_itoa(num1);
	str2 = ft_itoa(num2);
	str3 = ft_itoa(num1);

	printf("Number: %d, String: %s\n", num1, str1);
	printf("Number: %d, String: %s\n", num2, str2);
	printf("Number: %d, String: %s\n", num3, str3);
	return 0;
}*/
