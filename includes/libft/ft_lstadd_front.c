/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:27:21 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:44:00 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1st arg is a ptr to the head of the linked list.
// 2nd arg is a ptr to the new node to be added to the front of list.
// new->next = *lst; sets the ptr of the new node to the location
// of the original head of  the list.
// *lst = new; this makes the new node the head of the list.
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
