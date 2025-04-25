/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long_safe_atoi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:53:08 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:06 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safe_atoi_util(const char *str, int *i, long long *result, int *error)
{
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		if ((*result) > (LLONG_MAX - (str[(*i)] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
		(*result) = (*result) * 10 + (str[(*i)] - '0');
		(*i)++;
	}
	return (1);
}

long long	ft_safe_atoi(const char *str, int *error)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!safe_atoi_util(str, &i, &result, error))
		return (0);
	if (str[i] != '\0')
		*error = 1;
	return (result * sign);
}
