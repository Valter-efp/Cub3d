/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:57:41 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:03 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if (!new) - nothing to add, simply return.
// if (!*lst) - no lst, then create new and return.
// temp = ft_lstlast(*lst); - finds the last element of lst.
// temp->next = new; - writes the pointer to the NOW last element
// of the list on the previous last one.

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
