/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:07:50 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/22 18:52:24 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderbig(long *stk, long *stk2, int dig)
{
	int half;
	int small;
	int stka;

	half = dig / 2;
	stka = dig;
	while (stka > 4)
	{
		small = ft_findsmaller(stk, dig);
		if (small < half)
			ft_rra(stk, stk2, small, dig);
		else
			ft_ra(stk, stk2, small, dig);
		stka--;
	}
	printf ("%s",ft_ordertree(stk, dig));
	while (stka++ < dig)
		printf ("pa\n");
}


void		ft_rra(long *stk, long *stk2, int small, int dig)
{
	while (small-- > 0)
	{
		ft_move(stk, stk2, dig, "rra");
		printf ("rra\n");
	}	
	ft_move(stk, stk2, dig, "pb");
	printf ("pb\n");
}
void		ft_ra(long *stk, long *stk2, int small, int dig)
{
	int top;
	top = ft_findtop(stk, dig);
	while (small++ < top)
	{
		ft_move(stk, stk2, dig, "ra");
		printf ("ra\n");
	}
	ft_move(stk, stk2, dig, "pb");
	printf ("pb\n");
}