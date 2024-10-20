/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:32:18 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/20 23:48:35 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ret_clear(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;
	void	*tmp;

	first = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
			return (ret_clear(&first, del));
		new = ft_lstnew(tmp);
		if (!new)
		{
			free(tmp);
			return (ret_clear(&first, del));
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
