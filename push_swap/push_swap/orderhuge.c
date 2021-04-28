/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhuge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:44:32 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/28 20:42:14 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderhuge(long *stk, long *stk2, int dig)
{
	long	*ord;

	ord = ft_stacks(dig, stk);
	ft_orderstack(stk, ord, dig);
	ft_orderfi(stk, stk2, ord, dig);
	ft_printstacks (stk, stk2, dig);
}

void		ft_orderstack(long *stk, long *ord, int dig)
{
	int 	i;
	long	bigger;

	i = dig - 1;
	bigger = stk[ft_findbigger(stk, dig)];
	ord[i--] = bigger;
	while (i > 0)
	{
		ord[i] = ft_biggerthan(stk, bigger, dig);
		bigger = ord[i];
		i--;
	}
	ord[0] = 3000000000;
}

long	ft_biggerthan(long *stk, long bigger, int dig)
{
	int 		i;
	long int	j;

	i = 0;
	j = 0;
	while (++i < dig)
		if (stk[i] > j && stk[i] < bigger)
			j = stk[i];
	return (j);
}

void	ft_orderfi (long *stk, long *stk2, long *ord, int dig)
{
	int half;
	int count;
	
	count = dig - 1;
	half = dig / 2;
	// printf ("ord50 is %li, stk is %li\n", ord[50], stk[count]);
	while (count > half)
	{
		if (stk[count] < ord[50])
			ft_ra(stk, stk2, count, dig);
		count--;
	}
	while (count > 0)
	{
		if (stk[count] < ord[50])
			ft_rra(stk, stk2, (count - 1), dig);
		count--;
	}
}