/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:34:39 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/30 19:53:44 by ineumann         ###   ########.fr       */
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

int			ft_findbigger(long *stk, int dig)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dig-- > 1)
	{
		if (stk[dig] > j)
		{
			i = dig;
			j = stk[i];
		}
	}
	return (i);
}

int			ft_findsmaller(long *stk, int dig)
{
	int 		i;
	long int	j;
	int			k;

	i = 0;
	j = 3000000000;
	while (++i < dig)
	{
		if (stk[i] < j)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}