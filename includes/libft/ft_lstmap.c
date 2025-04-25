/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 08:45:13 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:46 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Create a new lst applying `f` */
/* `tempnewlst` = ft_lstnew(f(lst->content)); - apply (f) to the the */
/* 1st nod of lst store the value in (tempnewlst). */
/* `content` - Store the transformed node. */
/* `tempnewlst` - a ptr to the newlly created list */
/* `ft_lstadd_back` - keep adding the new content to the new lst */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*content;
	t_list	*tempnewlst;

	newlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tempnewlst = ft_lstnew(content);
		if (!tempnewlst)
		{
			ft_lstclear(&newlst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tempnewlst);
		lst = lst->next;
	}
	return (newlst);
}
