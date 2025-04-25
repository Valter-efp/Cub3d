/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:18:06 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:57 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **args, void (*del)(void *))
{
	int	i;

	i = 0;
	while (args[i])
	{
		del(args[i]);
		i++;
	}
	del(args);
}
