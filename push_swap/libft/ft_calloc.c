/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:19:00 by ineumann          #+#    #+#             */
/*   Updated: 2020/08/07 18:17:22 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t tam)
{
	void	*pnt;

	pnt = malloc(num * tam);
	if (pnt == NULL)
		return (NULL);
	ft_bzero(pnt, num * tam);
	return (pnt);
}
