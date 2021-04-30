/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhuge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:44:32 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/30 17:20:26 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderhuge(long *stk, long *stk2, int dig)
{
	long	*ord;

	ord = ft_stacks(dig, stk);
	ft_orderstack(stk, ord, dig);
	ft_printstacks (stk, stk2, dig);
	ft_orderfi(stk, stk2, ord, dig);
	ft_orderbig(stk, stk2, dig, 0);
	ft_orderbig(stk, stk2, dig, 1);
	ft_printstacks (stk, stk2, dig);
	free(ord);
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
	int topb;
	int	cut;
	
	ord[0] = 1;
	cut = 50;
	count = dig - 1;
	half = count / 2;
	while (count > 0)
	{
		if (stk[count] <= ord[cut])
		{
			if (count > 0)
				ft_ra(stk, stk2, count, dig);
			if (count < 0)
				ft_rra(stk, stk2, 8, dig);
			count = ft_findtop(stk, dig) + 1;
			topb = ft_findtop(stk2, dig) + 1;
 			ft_rrr (stk2, ft_stacks(topb, stk2), topb);
		}
		count--;
		if (count == 0 && dig > (cut + 50))
		{
			count = ft_findtop(stk, dig) + 1;
			cut += 50;
		}
	}
}

void 	ft_rrr (long *stk, long *ord, int top)
{
	int half;

	half = top / 2;
	ft_orderstack(stk, ord, top);
	if (stk[top - 1] < ord[half - 2])
	{
		ft_move(stk, ord, top, "ra");
		printf ("rb\n");
	}
	free(ord);
}
