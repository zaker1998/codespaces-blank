/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:00:00 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/14 15:00:00 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next_node_holder;

	if (!lst || !*lst || !del)
	{
		return ;
	}
	temp = *lst;
	while (temp)
	{
		next_node_holder = temp->next;
		del(temp->content);
		free(temp);
		temp = next_node_holder;
	}
	*lst = NULL;
}
