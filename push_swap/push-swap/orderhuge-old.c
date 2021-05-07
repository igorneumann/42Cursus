/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhuge-old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:44:32 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/07 21:07:00 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderhundred(long *stk, long *stk2, int dig)
{
	void	*ord;
	int		cut;
	
	cut = ((dig / 2) - (dig / 10));
	ord = ft_orderfi(stk, stk2, cut, dig);
	ft_orderbig(stk, stk2, dig, 1);
	free(ord);	
//	ord = ft_orderrev(stk, stk2, (cut / 2), dig);
//	ft_orderleft(stk, stk2, dig);
//	free(ord);	
//	ord = ft_orderfi(stk, stk2, (cut / 4), dig);
	ft_orderleft(stk, stk2, dig);
//	free(ord);	
	ft_printstacks (stk, stk2, dig);
}

void		ft_orderstack(long *stk, long *ord, int dig)
{
	int 	i;
	long	bigger;

	i = dig - 1;
	bigger = stk[ft_findbigger(stk, dig, 0)];
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

void	*ft_orderfi (long *stk, long *stk2, int cut, int dig)
{
	int count;
	int topb;
	long *ord;
	
	ord = ft_stacks(dig, stk);
	ft_orderstack(stk, ord, dig);
	count = dig - 1;
	while (count > 0)
	{
		if (stk[count] <= ord[cut])
		{
			ft_ra(stk, stk2, count, dig);
			count = ft_findtop(stk, dig) + 1;
			topb = ft_findtop(stk2, dig) + 1;
			//ft_rrr (stk2, ft_stacks(topb, stk2), topb);
		}
		count--;
		if (count == 0 && dig > (cut + (cut / 4)))
		{
			count = ft_findtop(stk, dig) + 1;
			cut += (cut / 4);
		}
		else if (count == 0)
			break;
	}
	return(ord);
}


void	*ft_orderrev (long *stk, long *stk2, int cut, int dig)
{
	int count;
	int topb;
	long *ord;
	
	ord = ft_stacks(dig, stk2);
	ft_orderstack(stk2, ord, dig);
	count = dig - 1;
	while (count > 0)
	{
		if (stk2[count] >= ord[(dig - cut)])
		{
			ft_rb(stk, stk2, count, dig);
			count = ft_findtop(stk2, dig) + 1;
			topb = ft_findtop(stk, dig) + 1;
			//ft_rrr (stk2, ft_stacks(topb, stk), topb);
		}
		count--;
		if (count == 0 && dig > (cut + cut))
		{
			count = ft_findtop(stk2, dig) + 1;
			cut += cut;
		}
	}
	return(ord);
}


void 	ft_rrr (long *stk, long *ord, int top)
{
	int half;
	half = top / 2;
	ft_orderstack(stk, ord, top);
	if (top > 2 && stk[top - 1] < ord[half])
	{
		ft_move(stk, ord, top, "ra");
		printf ("rb\n");
	}
	free(ord);
}
