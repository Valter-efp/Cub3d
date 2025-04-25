/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:03:40 by valter            #+#    #+#             */
/*   Updated: 2025/02/03 15:44:38 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if the given argument is a numeric string.
/// The string can start with a '+' or '-'.
/// @param arg The argument string to check.
/// @return 1 if the argument is numeric, 0 otherwise.
int	ft_is_numeric_argument(const char *arg)
{
	size_t	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
