/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:34:39 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/13 20:56:26 by ineumann         ###   ########.fr       */
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
	int 	j;
	int		k;

	j = 0;
	while (dig-- > 1)
	{
		if (stk[dig] > j)
		{
			j = stk[dig];
			k = dig;
		}
	}
	return (k);
}

int			ft_findsmaller(long *stk, int dig, int func, int buff)
{
	int 		i;
	int			k[buff];
	
	i = 0;
	while (i < buff)
		k[i++] = 0;
	i = 0;
	k[0] = ft_findbiggerthan(stk, dig, -2147483648);
	while (++i < buff)
		k[i] = ft_findbiggerthan(stk, dig, stk[k[i - 1]]);
	return (k[func]);
}

int			ft_findbig(long *stk, int dig, int func, int buff)
{
	int 		i;
	int			k[buff];
	
	i = 0;
	while (i < buff)
		k[i++] = 0;
	i = 0;
	k[0] = ft_findsmallerthan(stk, dig, 2147483649);
	while (++i < buff)
		k[i] = ft_findsmallerthan(stk, dig, stk[k[i - 1]]);
	return (k[func]);
}

int			ft_findbiggerthan(long *stk, int dig, long smaller)
{
	int 		i;
	long int	j;
	int			k;
	
	i = 0;
	k = 0;
	i = 0;
	j = 3000000000;
	while (++i < dig)
	{
		if (stk[i] < j && stk[i] > smaller)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}
int			ft_findsmallerthan(long *stk, int dig, long bigger)
{
	int 		i;
	long int	j;
	int			k;
	
	i = 0;
	k = 0;
	i = 0;
	j = -3000000000;
	while (++i < dig)
	{
		if (stk[i] > j && stk[i] < bigger)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}