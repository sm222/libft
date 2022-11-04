/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:12:24 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/04 01:28:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_tmp;
	t_list	*list;

	list = NULL;
	while (lst != NULL)
	{
		new_tmp = ft_lstnew(f(lst->content));
		if (!new_tmp)
		{
			ft_lstclear(&list, del);
			break ;
		}
		ft_lstadd_back(&list, new_tmp);
		lst = lst->next;
	}
	return (list);
}
