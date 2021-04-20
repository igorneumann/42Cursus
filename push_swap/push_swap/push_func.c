/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:34:39 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/20 20:40:36 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_stkdup(long int *s, int size)
{
	int		i;
	long	*pnt;

	i = size;
	pnt = malloc(i * sizeof(long));
	if (pnt == NULL)
		return (NULL);
	while (--i >= 0)
		pnt[i] = s[i];
	return (pnt);
}