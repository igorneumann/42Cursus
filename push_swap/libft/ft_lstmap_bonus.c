/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:29:48 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/23 20:33:45 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*cpy;
	t_list	*nxt;

	if (lst && f)
	{
		nxt = ft_lstnew(lst->content);
		res = nxt;
		if (!(res->content = f(res->content)))
			del(res->content);
		while (lst->next != NULL)
		{
			lst = lst->next;
			cpy = ft_lstnew(lst->content);
			if (!(cpy->content = f(cpy->content)))
				del(cpy->content);
			nxt->next = cpy;
			nxt = cpy;
		}
		return (res);
	}
	return (0);
}
