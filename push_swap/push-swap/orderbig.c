/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:07:50 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/30 18:15:05 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderbig(long *stk, long *stk2, int dig, int ord)
{
	int half;
	int small;
	int stka;

	half = dig / 2;
	stka = dig;
	while (stka > 4 || (stka > 0 && ord == 1))
	{
		if (ord == 0)
			small = ft_findsmaller(stk, dig);
		if (ord == 1)
			small = ft_findbigger(stk2, dig);
		if (small <= half && ord == 0)
			ft_rra(stk, stk2, small, dig);
		if (small > half && ord == 0)
			ft_ra(stk, stk2, small, dig);
		if (small <= half && ord == 1)
			ft_rrb(stk, stk2, small, dig);
		if (small > half && ord == 1)
			ft_rb(stk, stk2, small, dig);
		stka--;
	}
	printf ("%s",ft_ordertree(stk, dig));
	while (stka++ < dig)
		printf ("pa\n");
}


void		ft_rra(long *stk, long *stk2, int small, int dig)
{
	char cad[3];

	cad[0] = 'r';
	cad[2] = 'a';
	while (small-- > 0)
	{
		cad[1] = 'r';
		ft_move(stk, stk2, dig, cad);
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

void		ft_rrb(long *stk, long *stk2, int small, int dig)
{
	char cad[3];

	cad[0] = 'r';
	cad[2] = 'b';
	while (small-- > 0)
	{
		cad[1] = 'r';
		ft_move(stk, stk2, dig, cad);
		printf ("rrb\n");
	}	
	ft_move(stk, stk2, dig, "pa");
	printf ("pb\n");
}

void		ft_rb(long *stk, long *stk2, int small, int dig)
{
	int top;
	top = ft_findtop(stk2, dig);
	while (small++ < top)
	{
		ft_move(stk, stk2, dig, "rb");
		printf ("rb\n");
	}
	ft_move(stk, stk2, dig, "pa");
	printf ("pb\n");
}