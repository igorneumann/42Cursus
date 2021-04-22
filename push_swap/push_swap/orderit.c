/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:02:36 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/22 18:40:35 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderit(long *stk, long *stk2, int dig)
{
	if (dig == 3)
		printf ("sa");
	else if (dig == 4)
		printf ("%s", ft_ordertree(stk, dig));
	else if (dig > 4 && dig < 99)
		ft_orderbig(stk, stk2, dig);
}

char*		ft_ordertree(long *stk, int dig)
{
	int bigger;

	bigger = ft_findbigger(stk, dig);
//	printf ("bigger is %i\n", bigger);
//	ft_printstacks (stk, stk, dig);
	if (bigger == 3)
	{
		if (stk[2] > stk[1])
			return ("ra\nsa\n");
		else
			return ("ra\n");
	}
	else if (bigger == 2)
	{
		if (stk[3] > stk[1])
			return ("rra\n");
		else
			return ("sa\nra\n");
	}
	else
		return ("sa\n");
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
			j = stk[dig];
			i = dig;
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