/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:43:12 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Linked lists are like arrays, but only have 2 blocks for data
// block 1 for the content, and block 2 a pointer to the next list
// the linked list memories dont need to be contiguos.
// When we reach the last list the next will be NULL.
// We typsat the pointer provided by malloc and the size
// to the type t_list t_list type has been defined in libft.h.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	if (!content)
		node->content = NULL;
	else if (!node->content)
	{
		free(node);
		return (NULL);
	}
	return (node);
}
