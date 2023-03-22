/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:43:14 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/18 18:10:10 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	res = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
