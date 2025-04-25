/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:18:31 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:54 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Since I declared "res" as an unsigned int
in the return statement I must force it to be returned as int*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			||str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] - '0' >= 0) && (str[i] - '0' <= 9))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)res * sign);
}

/* int	main()
{
	printf("%d", ft_atoi("      -1234ab56"));
	return(0);
} */