/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:59:02 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/14 14:59:03 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append(t_list **new_list, t_list *new_node, t_list **current)
{
	if (!*new_list)
	{
		*new_list = new_node;
		*current = *new_list;
	}
	else
	{
		(*current)->next = new_node;
		*current = new_node;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;
	void	*content;

	new_list = NULL;
	new_node = NULL;
	current = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		append(&new_list, new_node, &current);
		lst = lst->next;
	}
	return (new_list);
}
