/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:34:46 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:38 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Takes a pointer to the beggining of a list.
// In the loop we iterate through each position of the list.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
