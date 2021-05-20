/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:07:50 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/19 20:13:31 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_orderbig(long *stk, long *stk2, int dig)
{
	int		small;
	int		stka[2];
	char	*three;

	stka[1] = dig / 2;
	stka[0] = dig;
	while (stka[0] > 4)
	{
		small = ft_findbiggerthan(stk, dig, -3000000000);
		if (small <= stka[1])
			ft_rra(stk, stk2, small, dig);
		if (small > stka[1])
			ft_ra(stk, stk2, small, dig);
		stka[0]--;
	}
	if (stk[1] < stk[2] || stk[2] < stk[3])
	{
		three = ft_ordertree(stk, dig);
		printg (three);
	}
	while (stka[0]++ < dig)
	{
		ft_move(stk, stk2, dig, "pa");
		printg ("pa\n");
	}
}

void	ft_orderleft(long *stk, long *stk2, int dig)
{
	int	half;
	int	big;
	int	stkb;

	stkb = dig;
	while (stkb > 1)
	{
		half = (stkb / 2);
		big = ft_findsmallerthan(stk2, dig, 2147483649);
		if (big <= half)
			ft_rrb(stk, stk2, big, dig);
		if (big > half)
			ft_rb(stk, stk2, big, dig);
		stkb--;
	}
}

void	ft_rra(long *stk, long *stk2, int small, int dig)
{
	char	cad[3];

	cad[0] = 'r';
	cad[2] = 'a';
	while (small-- > 0)
	{
		cad[1] = 'r';
		ft_move(stk, stk2, dig, cad);
		printg ("rra\n");
	}	
	ft_move(stk, stk2, dig, "pb");
	printg ("pb\n");
}

void	ft_ra(long *stk, long *stk2, int small, int dig)
{
	int	top;

	top = ft_findtop(stk, dig);
	while (small++ < top)
	{
		ft_move(stk, stk2, dig, "ra");
		printg ("ra\n");
	}
	ft_move(stk, stk2, dig, "pb");
	printg ("pb\n");
}
