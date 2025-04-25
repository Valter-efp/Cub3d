/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:17:00 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:51 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoll(const char *nptr)
{
	unsigned long long		i;
	int						sign;
	char					*temp;

	i = 0;
	sign = 1;
	if (!nptr || !(*nptr))
		return (0);
	temp = (char *)nptr;
	while (*temp == ' ' || (*temp >= '\t' && *temp <= '\r'))
		temp++;
	if (*temp == '-' || *temp == '+')
	{
		if (*temp == '-')
			sign *= -1;
		temp++;
	}
	while (*temp >= '0' && *temp <= '9')
	{
		i = i * 10 + (*temp - '0');
		temp++;
	}
	return (i * sign);
}
