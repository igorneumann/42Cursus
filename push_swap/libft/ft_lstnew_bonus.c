/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:49:53 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/13 16:49:55 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		lst->content = NULL;
	else
	{
		if (!(lst->content = malloc(sizeof(content))))
			return (NULL);
		lst->content = content;
	}
	lst->next = NULL;
	return (lst);
}
